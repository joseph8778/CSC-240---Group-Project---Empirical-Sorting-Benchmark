#pragma once

#include <iosfwd>

class SortMetrics;

// OWNER: The caller owns the output stream and metrics.
// OBSERVERS: The formatter uses these objects only during each call.

// Preconditions: output is ready for writing.
// Postconditions: writes the benchmark table headings to output.
void printBenchmarkHeader(std::ostream& output);

// Preconditions: output is ready for writing and metrics contains a completed
// sort run for the given algorithm, input type, and size.
// Postconditions: writes one benchmark result row to output.
void printBenchmarkRow(std::ostream& output, const char* algorithm, const char* inputType, int size, const SortMetrics& metrics);