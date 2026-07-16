
#include "../extraction/text.cpp"
#include "../helpers/opendoc.hpp"
#include "../helpers/open_result.hpp"
#include <string>
#include <stdexcept>

int main() {

    try {
 
    OpenResult result = open_doc("../PDFs/01_The_Birth_of_the_Universe.pdf");

    std:: string text = extract_text(result.doc);

    } catch (const std::exception&e)
    {
        std::cerr << e.what() << '\n';
        return 1;

    }

}



