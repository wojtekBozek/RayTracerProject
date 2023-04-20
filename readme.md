Author: Wojtek B. (email: wboojztee@gmail.com)

Copyright (c) 2023

Created with usage of code editor Visual Studio Code using MSBuild .exe to compile realese and debug. After some fun with CMake I managed to compile my project from CMakeLists on WSL, I hope it will be cross platform to some degree. I prefer to store CMakeList in separate directory, hence compile directory in a project. I will possibly create some .bat and .bash scripts for smoother configuration. Currently proposed procedure: mkdir build, then: cmake ../compile/. From my results it is significantly faster on Linux. After compiling run with: ./MyRayTracer and optional agruments: <window_height> <window_width> <camera_z-position>

These CPU Ray-Tracer project was created as my own goal to obtain knowlegde and understanding of basic concept related to computer graphics, as well as to gain more understanding of OOP. The project was intended to not rely on any external libraries like glm.

Main bases of information was Piter Shirley book: "Ray Tracing in One Weekend" https://www.realtimerendering.com/raytracing/Ray%20Tracing%20in%20a%20Weekend.pdf, as well as materials created by Scratchapixel: https://www.scratchapixel.com/index.html. 

As such all my codeis also available under the Fair Use terms. I also encourage you to contact me in case of any questions, comments and suggestions. All feedback, especially concerning any programming habbits, tips or messages of concern regarding some of proposed solutions are welcome. 

The proposed solution is under no term finished, as numerous new things may be implemented. These includes such concepts as:
- implementing materials with scatter funcion (it is under development as well as real path tracer, but there are some problems with getting refractions right, as well as I am not fully happy with reflections currently not interacting with sky color. This aproach changes few things in the way I implemented rendering pipeline, and althought it is not very hard to modify code, and diffusion already looks nicer with colors passing between objects, getting intended results in other aspects seems more challanging for now).
- movable and rotatable camera that was under development but for now was scrapted due to poor results.
- implementing real path-tracing algorithm.
- implementation of differnet lighting model.
- possible changes to the way reflective and refractive materials have been implemented.
- adding and testing emissive property in Phong model as it wasn't properly implemented, used and tested yet.
- Disney principled BRDF.
- Accelerating structures.
- Triangle and triangle meshes. 
- loading meshes and their material properties from obj or other files format.
- Writing to different file type, e.g. png, jpg.
- And of course user interface

As such the current phase of project will serve as my base for further getting knowledge in computer graphics.
