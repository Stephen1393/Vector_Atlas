#include "text.hpp"
#include <mupdf/fitz.h>
#include <mupdf/pdf.h>
#include <string>
#include <iostream>
#include "../helpers/open_result.hpp"
#include <stdexcept>

std:: string  extract_text(OpenResult result) {
  
   //use ctx and doc from OpenResult - keeping it same throughout pipline
   
   fz_context *ctx = result.ctx;
   fz_document *doc = result.doc;

     std:: string total = ""; 
   
      int pages = fz_count_pages(ctx,doc);

     //start of pages loop... 

         for (int page_count{0}; page_count < pages; ++page_count) {
      
            fz_stext_page* struc = nullptr;
            fz_device* dev = nullptr;
            fz_buffer* buf = nullptr;
            fz_output* output = nullptr;
            fz_page* page = nullptr;
      
         
         fz_try(ctx) { //start try/catch...
      
      
            page = fz_load_page(ctx, doc, page_count);
            
            // load page

            fz_rect bounds = fz_bound_page(ctx, page);

            //get the page boundaries

            struc = fz_new_stext_page(ctx, bounds);
            
            //an empty containe

            dev = fz_new_stext_device(ctx, struc, nullptr);

            //create extracting text device -- knows how to read PDF
      
            fz_run_page(ctx, page, dev, fz_identity, nullptr);
      
            //renders page - device sees drawing instructions, stores them in struc

            fz_close_device(ctx, dev);

            //close device - no more data will be written in struc
      
            buf = fz_new_buffer(ctx, 1024);
      
            //creates space in memory to allow bytes
      
            output = fz_new_output_with_buffer(ctx, buf);
      
            //stream that flows to the space in memory
      
            fz_print_stext_page_as_text(ctx, output, struc);
           
            //prints characters from struc into output

            fz_close_output(ctx, output);
      
            std::string text = fz_string_from_buffer(ctx, buf);

            total = text;
            
               }  fz_always(ctx) {
      
                  fz_drop_buffer(ctx, buf);
                  fz_drop_device(ctx, dev);
                  fz_drop_stext_page(ctx, struc);
                  fz_drop_page(ctx, page);
               } 
               
               fz_catch(ctx) { 
                  
                  throw std:: runtime_error(fz_caught_message(ctx));
               
               } //ends error check
            
            } //end loop

         return total;
      }