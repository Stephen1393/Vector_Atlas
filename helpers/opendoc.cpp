#include "opendoc.hpp"
#include <mupdf/fitz.h>
#include <mupdf/pdf.h>
#include <iostream>
#include <string>
#include "open_result.hpp"
#include "stdexcept"

OpenResult open_doc(const std:: string&path) {

  OpenResult result;
  
    fz_context *ctx = fz_new_context(nullptr, nullptr, FZ_STORE_DEFAULT);

    fz_register_document_handlers(ctx);

    fz_try(ctx) {

    fz_document *doc = fz_open_document(ctx, path.c_str());

    doc = result.doc; 
    ctx = result.ctx;
  
    } fz_catch(ctx) { 

        throw std:: runtime_error(fz_caught_message(ctx));
      }

  return result;

}