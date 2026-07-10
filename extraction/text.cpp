#include "text.hpp"
#include <mupdf/fitz.h>
#include <mupdf/pdf.h>
#include <string>
#include <iostream>

void extract_text() {

fz_context *ctx = fz_new_context(nullptr, nullptr, FZ_STORE_DEFAULT);

//context allows us to use functions needed

fz_document *doc = fz_open_document(ctx, "./PDFS/01_The_Birth_of_the_universe.pdf");

//open PDF document

int pages = fz_count_pages(ctx,doc);

int page_count = 0;
std:: string result = "";

fz_page *page = fz_load_page(ctx,doc,page_count); {

   for (int page_count{0}; page_count <= pages; ++page_count);

//load page number

fz_stext_page *struc = fz_keep_stext_page(ctx, struc);

//is a page containing structured text from PDF

fz_device *dev = fz_new_stext_device(ctx, struc, nullptr);

fz_run_page(ctx, page, dev, fz_identity, nullptr);

fz_buffer *buf = fz_new_buffer(ctx, 1024);

//creates space in memory to allow bytes

fz_output * output = fz_new_output_with_buffer(ctx, buf);

//stream that flows to the space in memory

fz_print_stext_page_as_text(ctx, output, struc);

//prints text from structured text page

std::string text = fz_string_from_buffer(ctx, buf);


result = result + text;

};


fz_drop_page(ctx, page);

//drops page to free memory


}


