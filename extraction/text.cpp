#include "text.hpp"
#include <mupdf/fitz.h>
#include <mupdf/pdf.h>

void extract_text() {

fz_context *ctx = fz_new_context(nullptr, nullptr, FZ_STORE_DEFAULT);

//context allows us to use functions needed

fz_document *doc = fz_open_document(ctx, "");

//open PDF document

fz_page *page = fz_load_page(ctx,doc,0);

//load page number

fz_stext_page *struc = fz_keep_stext_page(ctx, struc);

//is a page containing structured text from PDF

fz_device *dev = fz_new_stext_device(ctx, struc, nullptr);

//create a device to extract text

fz_run_page(ctx, page, dev, fz_identity, nullptr);

//renders page

fz_drop_page(ctx, page);

//drops page to free memory


}

