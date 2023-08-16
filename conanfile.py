from conan import ConanFile
from conan.tools.files import get, collect_libs
from conan.tools.cmake import CMakeToolchain, CMake, CMakeDeps, cmake_layout


class FifeChan(ConanFile):
    name = "fifechan"
    version = "0.1.6"
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "CMakeLists.txt", "src/*", "include/*",  "CMake/*"

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        self.requires("sdl_image/2.0.5")
        self.requires("sdl_ttf/2.20.2")
        self.requires("sdl/2.26.5")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.set_property("cmake_module_file_name", "FifeChan")
        self.cpp_info.set_property("cmake_module_target_name", "FifeChan::FifeChan")
        self.cpp_info.set_property("cmake_file_name", "FifeChan")
        self.cpp_info.set_property("cmake_target_name", "FifeChan::FifeChan")
        self.cpp_info.libs = collect_libs(self)