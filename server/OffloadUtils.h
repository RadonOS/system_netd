/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _CLAT_UTILS_H
#define _CLAT_UTILS_H

#include <string>

namespace android {
namespace net {

int hardwareAddressType(const std::string& interface);

int getClatEgressMapFd(void);

int getClatEgressProgFd(bool with_ethernet_header);

int getClatIngressMapFd(void);

int getClatIngressProgFd(bool with_ethernet_header);

int openNetlinkSocket(void);

int processNetlinkResponse(int fd);

int tcQdiscAddDevClsact(int fd, int ifIndex);
int tcQdiscReplaceDevClsact(int fd, int ifIndex);
int tcQdiscDelDevClsact(int fd, int ifIndex);

int tcFilterAddDevIngressBpf(int fd, int ifIndex, int bpfFd, bool ethernet);
int tcFilterAddDevEgressBpf(int fd, int ifIndex, int bpfFd, bool ethernet);

}  // namespace net
}  // namespace android

#endif