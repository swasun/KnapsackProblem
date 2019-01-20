/*******************************************************************************
 * Copyright (C) 2019 Charly Lamothe, Doulkifouli Abdallah-Ali                 *
 *                                                                             *
 * This file is part of KnapsackProblem.                                       *
 *                                                                             *
 *   Licensed under the Apache License, Version 2.0 (the "License");           *
 *   you may not use this file except in compliance with the License.          *
 *   You may obtain a copy of the License at                                   *
 *                                                                             *
 *   http://www.apache.org/licenses/LICENSE-2.0                                *
 *                                                                             *
 *   Unless required by applicable law or agreed to in writing, software       *
 *   distributed under the License is distributed on an "AS IS" BASIS,         *
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
 *   See the License for the specific language governing permissions and       *
 *   limitations under the License.                                            *
 *******************************************************************************/

#include "utils.h"

int get_lines_number(FILE *file) {
    int lines;
    char c;

    lines = 0;
    fseek(file, 0, SEEK_SET);

    while (!feof(file)) {
        c = fgetc(file);
        if(c == '\n') {
            lines++;
        }
    }

    fseek(file, 0, SEEK_SET);

    return lines;
}
