#include "opendoc.hpp"
#include <mupdf/fitz.h>
#include <mupdf/pdf.h>
#include <iostream>
#include <string>
#include "open_result.hpp"

OpenResult open_doc(std:: string path) {

  OpenResult result;
  
    fz_context *ctx = fz_new_context(nullptr, nullptr, FZ_STORE_DEFAULT);

    fz_try(ctx) {

    fz_document *doc = fz_open_document(ctx, path.c_str());

    doc = result.doc; 
    ctx = result.ctx;

    } fz_catch(ctx) {
        
    fz_throw(ctx, FZ_ERROR_GENERIC, "Couldn't open PDF");

    fz_rethrow(ctx);
  
  }
  
  return result;

}