#include "text.hpp"
#include <mupdf/fitz.h>
#include <mupdf/pdf.h>
#include <string>
#include <iostream>
#include "../helpers/open_result.hpp"

std:: string  extract_text(fz_document* doc) {
  
   //use ctx and doc from OpenResult - keeping it same throughout pipline
   
   OpenResult result;

   fz_context *ctx = result.ctx;
   fz_document *doc = result.doc;

   fz_try(ctx) { //start out try/catch error...

   
      int pages = fz_count_pages(ctx,doc);

      int page_count = 0;
      std:: string total = ""; 


     //start of pages loop... 

      fz_page *page = fz_load_page(ctx,doc,page_count); {
      
         for (int page_count{0}; page_count < pages; ++page_count);
      
            fz_stext_page* struc = nullptr;
            fz_device* dev = nullptr;
            fz_buffer* buf = nullptr;
            fz_output* output = nullptr;
            fz_page* page = nullptr;
      
         
         fz_try(ctx) { //start inner try/catch...
      
      
            page = fz_load_page(ctx, doc, page_count);
      
            fz_stext_page *struc = fz_keep_stext_page(ctx, struc);
      
            //is a page containing structured text from PDF
      
            fz_device *dev = fz_new_stext_device(ctx, struc, nullptr);

            //create extracting text device
      
            fz_run_page(ctx, page, dev, fz_identity, nullptr);
      
            //renders page
      
            fz_buffer *buf = fz_new_buffer(ctx, 1024);
      
            //creates space in memory to allow bytes
      
            fz_output * output = fz_new_output_with_buffer(ctx, buf);
      
            //stream that flows to the space in memory
      
            fz_print_stext_page_as_text(ctx, output, struc);
      
            //prints text from structured text page
      
            std::string text = fz_string_from_buffer(ctx, buf);
            
            
            total = total + text;
      
      
               }  fz_always(ctx) {
      
                  fz_drop_page(ctx, page);
                  fz_drop_buffer(ctx, buf);
                  fz_drop_device(ctx, dev);
                  fz_drop_stext_page(ctx, struc);
               } 
               
               fz_catch(ctx) { 
                  
                  fz_throw(ctx, FZ_ERROR_GENERIC, "Couldn't load page number %d", page_count);
      
                  fz_rethrow(ctx);
               
               } //ends inner error
            
            } //end loop
         
         }  
         
         fz_always(ctx) {

            fz_drop_document(ctx, doc);
            fz_drop_context(ctx);
         }
         
      fz_catch(ctx) {
            fz_throw(ctx, FZ_ERROR_GENERIC, "couldn't load document");
         
         } //end outer error
      
      }






