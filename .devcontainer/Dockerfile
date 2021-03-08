FROM ubuntu:18.04

# Options for setup script
ARG INSTALL_ZSH="true"
ARG UPGRADE_PACKAGES="false"
ARG USERNAME=tashia
ARG USER_UID=1000
ARG USER_GID=$USER_UID
ARG LLVM_VERSION=12

# Install needed packages and setup non-root user. Use a separate RUN statement to add your own dependencies.
COPY library-scripts/common-debian.sh /tmp/library-scripts/
RUN apt-get update \
    && /bin/bash /tmp/library-scripts/common-debian.sh "${INSTALL_ZSH}" "${USERNAME}" "${USER_UID}" "${USER_GID}" "${UPGRADE_PACKAGES}" \
    && apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/* &&  rm -rf /tmp/library-scripts

# Install needed packages. Use a separate RUN statement to add your own dependencies.
# See this script https://apt.llvm.org/llvm.sh) to pick the right one
RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - \
    && add-apt-repository "deb http://apt.llvm.org/bionic/   llvm-toolchain-bionic-"${LLVM_VERSION}"  main" \
    && apt-get update \
    && apt-get install -y clang-"${LLVM_VERSION}" lldb-"${LLVM_VERSION}" lld-"${LLVM_VERSION}" clangd-"${LLVM_VERSION}" \
    && apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/ \
    && ln -s  /usr/bin/clang++-"${LLVM_VERSION}" /usr/bin/clang++ \
    && ln -s  /usr/bin/clang-"${LLVM_VERSION}" /usr/bin/clang \
    && ln -s  /usr/bin/clangd-"${LLVM_VERSION}" /usr/bin/clangd