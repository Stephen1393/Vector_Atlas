#include "../extraction/text.hpp"
#include "../helpers/opendoc.hpp"
#include "../helpers/open_result.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

int main() {

    OpenResult result;

    try {
 
    OpenResult result = open_doc("../PDFs/01_The_Birth_of_the_Universe.pdf");

    std:: string text = extract_text(result);

    return 0;

    } catch (const std::exception&e)
    {
        std::cerr << e.what() << '\n';
        return 1;

    }

    fz_drop_document(result.ctx, result.doc);
    fz_drop_context(result.ctx);

}


