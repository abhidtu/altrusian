/**
 * Copyright (c) 2016 Abhishek Chawla <abhidtu@gmail.com>
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <stack>

#ifndef VISITOR_H
#define VISITOR_H

using namespace std;

namespace altrusian {
    namespace graph {

        class DfsVisitor {

        public:
            virtual void onVertexDiscovery(int vertex) = 0;

        };

        class BfsVisitor {

        public:
            virtual void onVertexDiscovery(int vertex) = 0;

        };



    }
}

#endif //VISITOR_H
