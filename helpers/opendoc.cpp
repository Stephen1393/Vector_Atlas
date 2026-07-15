#include "opendoc.hpp"
#include <mupdf/fitz.h>
#include <mupdf/pdf.h>
#include <iostream>
#include <string>

fz_document* open_doc(std:: string path) {
    
    fz_context *ctx = fz_new_context(nullptr, nullptr, FZ_STORE_DEFAULT);

    fz_try(ctx) {

      fz_document *doc = fz_open_document(ctx, path.c_str());
    
    return doc;

    } fz_catch(ctx) {
        
    fz_throw(ctx, FZ_ERROR_GENERIC, "Couldn't open PDF");

    fz_rethrow(ctx);

}

}