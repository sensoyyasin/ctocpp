#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error!!" << std::endl;
        exit (1);
    }
    std::ifstream input;
    std::ofstream output;
    std::ofstream output2;
    std::string line;

    input.open(argv[1]);

    if (!input.is_open())
    {
        std::cerr << "Error couldn't read" << std::endl;
        exit (1);
    }
    output.open((std::string)argv[1] + ".cpp");
    if (!output.is_open())
    {
        std::cerr << "Error couldn't write" << std::endl;
        exit (1);
    }
    output << "#include <iostream>" << std::endl;
    while (std::getline(input, line))
    {
        output << line << std::endl;
    }

    input.close();
    output.close();

    return (0);
}