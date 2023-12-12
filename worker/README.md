
## windows下编译Mediasoup
- **准备环境**
  - 安装python
  - 安装 meson和ninja
    ```sh
    # 安装meson
    pip install  meson
    pip install ninja
    ```
- **生成vs工程**
  ```sh
  # Windows下生成visul studio 工程,如果出错清理之前的build目录
  meson setup --prefix "D:\workspaces\2.my_project\mediasoup\worker\out\Debug" --bindir "bin" --libdir "lib" --buildtype debug --backend vs -Db_pie=true -Db_staticpic=true --reconfigure -Dms_log_trace=true -Dms_log_file_line=true --vsenv ".\out\Debug\build"
  ```
- **Debug版本编译**
  ```sh
  # 需要通过vs控制台进入
  cd worker
  # windows下编译 Debug版本,如果偶尔卡住直接enter执行
  meson setup --prefix "D:\workspaces\2.my_project\mediasoup\worker\out\Debug" --bindir "bin" --libdir "lib" --buildtype debug -Db_pie=true -Db_staticpic=true --reconfigure -Dms_log_trace=true -Dms_log_file_line=true --vsenv ".\out\Debug\build"
  # %cd%
  # 生成FBS代码
  meson compile -C ".\out\Debug\build" flatbuffers-generator
  # 编译可执行程序
  meson compile -C ".\out\Debug\build" -j 2 mediasoup-worker
  # 编译静态库
  meson compile -C ".\out\Debug\build" -j 2 libmediasoup-worker
  ```
- **Release版本编译**
  ```sh
  # 需要通过vs控制台进入
  cd worker
  # windows下编译 Release版本
  meson setup --prefix "D:\workspaces\2.my_project\mediasoup\worker\out\Release" --bindir "" --libdir "" --buildtype release -Db_ndebug=true -Db_pie=true -Db_staticpic=true --reconfigure -Dms_log_trace=true -Dms_log_file_line=true --vsenv ".\out\Release\build"
  # 生成FBS代码
  meson compile -C ".\out\Release\build" flatbuffers-generator
  # 编译可执行程序
  meson compile -C ".\out\Release\build" -j 2 mediasoup-worker
  # 编译静态库
  meson compile -C ".\out\Release\build" -j 2 libmediasoup-worker
  ```