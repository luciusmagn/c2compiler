/* Copyright 2013-2018 Bas van den Berg
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef BUILDER_ROOT_FINDER_H
#define BUILDER_ROOT_FINDER_H

#include <string>
#include <limits.h>

namespace C2 {

class RootFinder {
public:
    RootFinder();

    void findTopDir();

    std::string orig2Root(const std::string& filename) const;
    std::string root2Orig(const std::string& filename) const;

    const char* getBuildFile() const;
private:
    char base_path[PATH_MAX];
    char rel_path[PATH_MAX];
    char* path_prefix;
};

}

#endif

