#include <iostream>
#include <string>
#include <time.h>


#include <yaml-cpp/yaml.h>
#include <docopt/docopt.h>

static const char USAGE[] =
R"(ENetzwerk

    Usage:
      ENetzwerk yaml 
      ENetzwerk (-h | --help)
      ENetzwerk --version

    Options:
      -h --help     Show this screen.
      --version     Show version.
)";


static const char VERSION[] = "ENetzwerk 0.1";


int main(int argc, const char** argv)
{


    std::map<std::string, docopt::value> args = docopt::docopt(USAGE, 
                                                  { argv + 1, argv + argc },
                                                  true,               // show help if requested
                                                  VERSION);  // version string

// print
//    for(auto const& arg : args) {
//        std::cout << arg.first << ": " << arg.second << std::endl;
//    } 



    std::cout << args["yaml"] << std::endl;
    if (args["yaml"].isBool() && args["yaml"].asBool() == true ){
      YAML::Node config = YAML::LoadFile("config.yaml");
      if (config["name"]) {
        std::cout << "Last logged in: " << config["name"] << "\n";
      }

    
    }





    return 0;
}
