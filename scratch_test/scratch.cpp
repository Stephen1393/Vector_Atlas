
#include "../extraction/text.cpp"
#include "../helpers/opendoc.hpp"
#include <string>

int main() {
 
    fz_document* doc = open_doc("../PDFs/01_The_Birth_of_the_Universe.pdf");

     std:: string text = extract_text(doc);

    if (!text.empty()) {

        std::cout << text << '.\n';
    }

    else {

        std:: cout << "Empty string" << '\n';
    }

    return 1;

}



