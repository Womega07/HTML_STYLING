#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>



class css
{

    
    public:

        int side_margin = 20;
        int top_margin = 5;
        std::string title_align = "center";
        std::string font_family = "sans-serif";

        css(){return;}

        css(int side_margin, std::string title_align, std::string font_family)
        {
            this->side_margin = side_margin;
            this->title_align = title_align;
            this->font_family = font_family;
        }

        std::string make_string(const std::string html)
        {
            std::stringstream style_header;
            style_header << "<style> \n"
                ".container"
                "{ "
                "margin-left:" << this->side_margin << "%;\n "
                "margin-right:" << this->side_margin << "%;\n "
                "margin-top:" << this->top_margin << "%;\n "

                "}\n"
                "h1, h2, h3, h4, h5, h6\n"
                "{\n"
                "text-align:" << this->title_align << ";\n"
                "}\n"
                "html *\n"
                "{\n"
                "font-family: " << this->font_family << ";\n"
                "}\n"
                "</style>\n"
                "<div class='container'>\n";

            std::string footer = "</div>";

            std::stringstream full_string;
            full_string << style_header.str() << html << footer;
            return full_string.str();
        }


};

int main(int argc, char ** argv)
{

    int opt;
    css style;

    while (( opt = getopt(argc, argv, "m:")) != -1)
    {
        switch(opt)
        {
            case 'm':
                style.side_margin = std::stoi(std::string(optarg));
                break;
            default:
                break;
        }
    }

    std::string input;
    for (std::string line; std::getline(std::cin, line);)
    {     input.append(line); continue;    }

//    css style(20, "center", "sans-serif");
    std::string output;
    output  = style.make_string(input);

    std::cout << output;
       

}
