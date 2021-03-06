// Copyright 2016 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CPU_INSTRUCTIONS_X86_PDF_PDF_DOCUMENT_PARSER_H_
#define CPU_INSTRUCTIONS_X86_PDF_PDF_DOCUMENT_PARSER_H_

#include "cpu_instructions/x86/pdf/pdf_document.pb.h"

namespace cpu_instructions {
namespace x86 {
namespace pdf {

typedef google::protobuf::RepeatedPtrField<PdfCharacter> PdfCharacters;
typedef google::protobuf::RepeatedPtrField<PdfTextSegment> PdfTextSegments;
typedef google::protobuf::RepeatedPtrField<PdfTextBlock> PdfTextBlocks;
typedef google::protobuf::RepeatedPtrField<PdfTextTableRow> PdfTextTableRows;
typedef google::protobuf::RepeatedPtrField<PdfPagePreventSegmentBinding>
    PdfPagePreventSegmentBindings;

// The one function doing all the logic: 'page' is passed in filled with
// 'characters'. The function aggregates the character flow into segments,
// segments into blocks and blocks into rows.
//
// PdfTextBlocks contained into 'rows' are cleanup up (trailing whitespaces are
// removed) and sorted in reading order (top to bottom, left to right).
//
// Users of PdfPage should ultimately use the 'rows' field but can still inspect
// the lower level constructs for debugging purpose.
//
// 'prevent_segment_bindings' instructs which which segments to never join in a
// block. This is needed because there are no easy heuristic to decide when not
// to join.
void Cluster(PdfPage* page,
             const PdfPagePreventSegmentBindings& prevent_segment_bindings =
                 PdfPagePreventSegmentBindings());

}  // namespace pdf
}  // namespace x86
}  // namespace cpu_instructions

#endif  // CPU_INSTRUCTIONS_X86_PDF_PDF_DOCUMENT_PARSER_H_
