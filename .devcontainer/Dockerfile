FROM ubuntu:18.04

# Install needed packages. Use a separate RUN statement to add your own dependencies.
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install software-properties-common wget build-essential cmake \
    # See this script https://apt.llvm.org/llvm.sh) to pick the right one
    && wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - \
    && add-apt-repository "deb http://apt.llvm.org/bionic/   llvm-toolchain-bionic-10  main" \
    && apt-get update \
    && apt-get install -y clang-10 lldb-10 lld-10 clangd-10 \
    && apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/

RUN ln -s  /usr/bin/clang++-10 /usr/bin/clang++ \
    && ln -s  /usr/bin/clang-10 /usr/bin/clang \
    && ln -s  /usr/bin/clangd-10 /usr/bin/clangd \