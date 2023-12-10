```sh
# 需要通过vs控制台进入
cd worker
# windows下编译 Debug版本
meson setup --prefix "D:\workspaces\2.my_project\mediasoup\worker\out\Debug" --bindir "" --libdir "" --buildtype debug -Db_pie=true -Db_staticpic=true --reconfigure -Dms_log_trace=true -Dms_log_file_line=true --vsenv ".\out\Debug\build"
# 生成FBS代码
meson compile -C ".\out\Debug\build" flatbuffers-generator
# 编译可执行程序
meson compile -C ".\out\Debug\build" -j 2 mediasoup-worker
# 编译静态库
meson compile -C ".\out\Debug\build" -j 2 libmediasoup-worker
```
- Release模式编译
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