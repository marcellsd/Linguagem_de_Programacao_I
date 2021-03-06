#include "App.h"

#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename){
    
}

int App::run(int argc, char* argv[]){
    
    if (argc == 1) {
        return show_usage(argv[0]);
    }

    std::string action = argv[1];

    if (action == "add"){
        if(argc == 2){
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        list_messages();
    } else if (action == "search"){
      search();
    } else {
        return show_usage(argv[0]);
    }

    return 0;
}

void App::add(){
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);
    add(message);
}

void App::add(const std::string message){

    diary.add(message);

}

void App::list_messages(){
    for(size_t i = 0; i < diary.messages_size; ++i){
        const Message& message = diary.messages[i];
        std::cout << "- " << message.content << std::endl;
    }
}

int App::show_usage(const std::string& program_name){
    std::cout << "To correctly use this program use one of the forms bellow:" << std::endl;
    std::cout << "> To add: " <<program_name << " add <message>.";
    std::cout << " or  simply: " << program_name << " add." << std::endl;
    std::cout << "> To list: " << program_name << " list." << std::endl;
    return 1;
}

void App::search(){
    std::string what;

    std::cout << "Please, enter the word to search:" << std::endl;
    std::getline(std::cin, what);
    
    Message* strcpr_return = diary.search(what);

    if(strcpr_return != nullptr){
        std::cout << strcpr_return->content << std::endl;
    } else{
        std::cout << "Word not found!" << std::endl;
    }
}
