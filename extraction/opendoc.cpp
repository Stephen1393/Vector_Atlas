#include "opendoc.hpp"
#include <mupdf/fitz.h>
#include <mupdf/pdf.h>
#include <iostream>
#include <string>

auto open_doc(std:: string path) {
    
    fz_context *ctx = fz_new_context(nullptr, nullptr, FZ_STORE_DEFAULT);

     fz_try(ctx) {

      fz_document *doc = fz_open_document(ctx, path.c_str()); 
    
    }
    fz_catch(ctx) {
        
        std:: cout << "file not found" << '\n';
    }

}