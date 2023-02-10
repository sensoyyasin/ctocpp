/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:35:17 by yasinsensoy       #+#    #+#             */
/*   Updated: 2023/02/10 18:35:19 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    std::string str;

    str = argv[1];
    input.open(argv[1]);

    if (!input.is_open())
    {
        std::cerr << "Error couldn't read" << std::endl;
        exit (1);
    }
    output.open(str.substr(0, 10) + ".cpp");
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