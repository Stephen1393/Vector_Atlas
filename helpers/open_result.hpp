#pragma once
#include <mupdf/fitz.h>

struct OpenResult {

    fz_context* ctx;
    fz_document* doc;
};