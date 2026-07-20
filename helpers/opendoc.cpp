#include "opendoc.hpp"
#include <mupdf/fitz.h>
#include <mupdf/pdf.h>
#include <iostream>
#include <string>
#include "open_result.hpp"
#include "stdexcept"

OpenResult open_doc(const std:: string&path) {

  OpenResult result;
  
    result.ctx = fz_new_context(nullptr, nullptr, FZ_STORE_DEFAULT);

    fz_register_document_handlers(result.ctx);

    fz_try(result.ctx) {

    result.doc = fz_open_document(result.ctx, path.c_str());
  
    } fz_catch(result.ctx) { 

        throw std:: runtime_error(fz_caught_message(result.ctx));
      }

  return result;

}