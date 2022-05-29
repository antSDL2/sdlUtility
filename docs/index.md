 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`namespace `[`AtUtility`](#namespace_at_utility) | Contains all class and function implementations of the project.
`namespace `[`AtUtility::Collision`](#namespace_at_utility_1_1_collision) | Functions used to detect collisions between 2D shapes.
`namespace `[`AtUtility::Files`](#namespace_at_utility_1_1_files) | Functions used to browse directories/files.
`namespace `[`AtUtility::Lua`](#namespace_at_utility_1_1_lua) | Functions used to execute [Lua](#namespace_at_utility_1_1_lua) scripts.
`namespace `[`AtUtility::Renderer`](#namespace_at_utility_1_1_renderer) | Functions used to setup OpenGL and render 2D shapes.
`namespace `[`AtUtility::Strings`](#namespace_at_utility_1_1_strings) | Functions used to manipulate strings.
`namespace `[`AtUtility::Vectors`](#namespace_at_utility_1_1_vectors) | Functions used to operate on std::vector structures.

# namespace AtUtility 

Contains all class and function implementations of the project.

## AtUtility Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AtUtility::Vector2`](#class_at_utility_1_1_vector2) | Used to describe a 2D vector as a set of (x, y) components.

# class AtUtility::Vector2 

Used to describe a 2D vector as a set of (x, y) components.

## AtUtility::Vector2 Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Vector2`](#class_at_utility_1_1_vector2_1a1642c6cd2f0ba129054d50e436651443)`(float X,float Y)` | Basic constructor.
`public  `[`~Vector2`](#class_at_utility_1_1_vector2_1a451c24af2288c3b2aadd95d0668101f0)`()` | Basic destructor.
`public void `[`operator=`](#class_at_utility_1_1_vector2_1ad8b41e977d8ead0c61a572ad8cd356e0)`(`[`Vector2`](#class_at_utility_1_1_vector2)` Vector)` | operator= implementation.
`public void `[`operator+=`](#class_at_utility_1_1_vector2_1afbcdbd65cc87304cde3cba49ce6fdc00)`(`[`Vector2`](#class_at_utility_1_1_vector2)` Vector)` | operator+= implementation.
`public void `[`operator-=`](#class_at_utility_1_1_vector2_1a3d341b6dd4047d40e00f46fe3dfe3b49)`(`[`Vector2`](#class_at_utility_1_1_vector2)` Vector)` | operator-= implementation.
`public bool `[`operator==`](#class_at_utility_1_1_vector2_1aa5d9faf600ddcb605340dda58108754b)`(`[`Vector2`](#class_at_utility_1_1_vector2)` Vector)` | operator== implementation.
`public bool `[`operator!`](#class_at_utility_1_1_vector2_1a7bf839908e3ca26be0794d061c7d557f)`()` | operator! implementation.
`public bool `[`operator!=`](#class_at_utility_1_1_vector2_1a76e6c6b4a6dedeab2ee2a42179a9f919)`(`[`Vector2`](#class_at_utility_1_1_vector2)` Vector)` | operator!= implementation.
`public float `[`Angle`](#class_at_utility_1_1_vector2_1a951485a8009404d7da0ce8e4dcd6b515)`()` | Returns the angle of the vector.
`public float `[`Length`](#class_at_utility_1_1_vector2_1a4758593a608c0ff9b5cf2f5b1480f3e8)`()` | Returns the magnitude of the vector.
`public float `[`Length2`](#class_at_utility_1_1_vector2_1aae9cd556c93665af68f66fb5c4f63c36)`()` | Returns the squared magnitude of the vector.
`public float `[`X`](#class_at_utility_1_1_vector2_1a3703e05c538b6f3ce6b7d9b0115258f9)`()` | Returns the X component of the vector.
`public float `[`Y`](#class_at_utility_1_1_vector2_1a173f7e4bb802f5d9639e9c352b016e54)`()` | Returns the Y component of the vector.
`protected float `[`x`](#class_at_utility_1_1_vector2_1aaae2839d75a413783b4c2b3cada9d3d0) | X component of the vector.
`protected float `[`y`](#class_at_utility_1_1_vector2_1ab295025e57b980091233988c415f9815) | Y component of the vector.

## AtUtility::Vector2 Members

#### `public  `[`Vector2`](#class_at_utility_1_1_vector2_1a1642c6cd2f0ba129054d50e436651443)`(float X,float Y)` 

Basic constructor.

#### Parameters
* `X` `Y` Used to initialise the x, y of the vector.

#### `public  `[`~Vector2`](#class_at_utility_1_1_vector2_1a451c24af2288c3b2aadd95d0668101f0)`()` 

Basic destructor.

#### `public void `[`operator=`](#class_at_utility_1_1_vector2_1ad8b41e977d8ead0c61a572ad8cd356e0)`(`[`Vector2`](#class_at_utility_1_1_vector2)` Vector)` 

operator= implementation.

Assigns the x, y values to the specified [Vector2](#class_at_utility_1_1_vector2).

#### `public void `[`operator+=`](#class_at_utility_1_1_vector2_1afbcdbd65cc87304cde3cba49ce6fdc00)`(`[`Vector2`](#class_at_utility_1_1_vector2)` Vector)` 

operator+= implementation.

Increments the x, y values by the specified [Vector2](#class_at_utility_1_1_vector2).

#### `public void `[`operator-=`](#class_at_utility_1_1_vector2_1a3d341b6dd4047d40e00f46fe3dfe3b49)`(`[`Vector2`](#class_at_utility_1_1_vector2)` Vector)` 

operator-= implementation.

Decrements the x, y values by the specified [Vector2](#class_at_utility_1_1_vector2).

#### `public bool `[`operator==`](#class_at_utility_1_1_vector2_1aa5d9faf600ddcb605340dda58108754b)`(`[`Vector2`](#class_at_utility_1_1_vector2)` Vector)` 

operator== implementation.

Compares the x, y values to the specified [Vector2](#class_at_utility_1_1_vector2).

#### `public bool `[`operator!`](#class_at_utility_1_1_vector2_1a7bf839908e3ca26be0794d061c7d557f)`()` 

operator! implementation.

Returns true if (x, y) = (0, 0).

#### `public bool `[`operator!=`](#class_at_utility_1_1_vector2_1a76e6c6b4a6dedeab2ee2a42179a9f919)`(`[`Vector2`](#class_at_utility_1_1_vector2)` Vector)` 

operator!= implementation.

Compares the x, y values to the specified [Vector2](#class_at_utility_1_1_vector2).

#### `public float `[`Angle`](#class_at_utility_1_1_vector2_1a951485a8009404d7da0ce8e4dcd6b515)`()` 

Returns the angle of the vector.

Calculated in relation to the origin point (0, 0).

#### `public float `[`Length`](#class_at_utility_1_1_vector2_1a4758593a608c0ff9b5cf2f5b1480f3e8)`()` 

Returns the magnitude of the vector.

#### `public float `[`Length2`](#class_at_utility_1_1_vector2_1aae9cd556c93665af68f66fb5c4f63c36)`()` 

Returns the squared magnitude of the vector.

#### `public float `[`X`](#class_at_utility_1_1_vector2_1a3703e05c538b6f3ce6b7d9b0115258f9)`()` 

Returns the X component of the vector.

#### `public float `[`Y`](#class_at_utility_1_1_vector2_1a173f7e4bb802f5d9639e9c352b016e54)`()` 

Returns the Y component of the vector.

#### `protected float `[`x`](#class_at_utility_1_1_vector2_1aaae2839d75a413783b4c2b3cada9d3d0) 

X component of the vector.

#### `protected float `[`y`](#class_at_utility_1_1_vector2_1ab295025e57b980091233988c415f9815) 

Y component of the vector.

# namespace AtUtility::Collision 

Functions used to detect collisions between 2D shapes.

## AtUtility::Collision Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`CalculateDrag`](#namespace_at_utility_1_1_collision_1af4233dc7f54e9c057070a9d58a41e011)`(float Velocity,float DragCoefficient,float Area)`            | Used to calculate a drag force for moving objects.
`public bool `[`DiskInDisk`](#namespace_at_utility_1_1_collision_1aeced385af4821879e0b1af5140adef5f)`(float X1,float Y1,float R1,float r1,float Angle1,float Direction1,float X2,float Y2,float R2,float r2,float Angle2,float Direction2,float & AdjustX,float & AdjustY)`            | Used to check for collision between two disks.
`public bool `[`DiskInRectangle`](#namespace_at_utility_1_1_collision_1ae7332d25854ebc0ba8e69d27eb6f7a8f)`(float X1,float Y1,float R1,float r1,float Angle1,float Direction1,float X2,float Y2,int Width2,int Height2,float Direction2,float & AdjustX,float & AdjustY)`            | Used to check for collision between a disk and a rectangle.
`public float `[`Clamp`](#namespace_at_utility_1_1_collision_1a2ead0d7cf367180eecf5f54b3e46b2bf)`(float Minimum,float Value,float Maximum)`            | Used to keep a float value within a specified range.
`public bool `[`PointInDisk`](#namespace_at_utility_1_1_collision_1a716dad565333216cce69b411dccc61df)`(float X1,float Y1,float X,float Y,float R,float r,float Angle,float Direction)`            | Used to check for collision between a point and a disk.
`public bool `[`PointInRectangle`](#namespace_at_utility_1_1_collision_1aebcee1a7daa7b8f62427e4e333d0fe9f)`(float X1,float Y1,float X,float Y,int Width,int Height,float Direction)`            | Used to check for collision between a point and a rectangle.
`public bool `[`PointInTriangle`](#namespace_at_utility_1_1_collision_1a6c983797093b524146068aa5c7957eaa)`(float X1,float Y1,float X,float Y,int Width,int Height,float Direction)`            | Used to check for collision between a point and an isosceles triangle.
`public bool `[`RectangleInRectangle`](#namespace_at_utility_1_1_collision_1a447c1d12735eeb2919ada3fc588f2faa)`(float X1,float Y1,int Width1,int Height1,float Direction1,float X2,float Y2,int Width2,int Height2,float Direction2,float & AdjustX,float & AdjustY)`            | Used to check for collision between a point and a rectangle.
`public void `[`RotatePointBy`](#namespace_at_utility_1_1_collision_1aa31b5926e581b7b336c09774c2bba58e)`(float & X1,float & Y1,float CenterX,float CenterY,float Angle)`            | Used to rotate a point around a center point by the specified angle.

## AtUtility::Collision Members

#### `public float `[`CalculateDrag`](#namespace_at_utility_1_1_collision_1af4233dc7f54e9c057070a9d58a41e011)`(float Velocity,float DragCoefficient,float Area)` 

Used to calculate a drag force for moving objects.

#### Parameters
* `Velocity` The velocity of the moving object. 

* `DragCoefficient` A drag coefficient. 

* `Area` The area of the object subjected to the drag force.

#### `public bool `[`DiskInDisk`](#namespace_at_utility_1_1_collision_1aeced385af4821879e0b1af5140adef5f)`(float X1,float Y1,float R1,float r1,float Angle1,float Direction1,float X2,float Y2,float R2,float r2,float Angle2,float Direction2,float & AdjustX,float & AdjustY)` 

Used to check for collision between two disks.

#### Parameters
* `X1` `Y1` `X2` `Y2` Coordinates of each disk. 

* `R1` `R2` External radius of each disk. 

* `r1` `r2` Internal radius of each disk. 

* `Angle1` `Angle2` Section (in radians) of each disk to be considered in the collision check. 

* `Direction1` `Direction2` Direction (in radians) to which each disk is pointing. Relevant if using a section of a disk. 

* `AdjustX` `AdjustY` Measured overlap between the two disks. Values returned by reference.

#### `public bool `[`DiskInRectangle`](#namespace_at_utility_1_1_collision_1ae7332d25854ebc0ba8e69d27eb6f7a8f)`(float X1,float Y1,float R1,float r1,float Angle1,float Direction1,float X2,float Y2,int Width2,int Height2,float Direction2,float & AdjustX,float & AdjustY)` 

Used to check for collision between a disk and a rectangle.

#### Parameters
* `X1` `Y1` `X2` `Y2` Coordinates of each shape. 

* `R1` External radius of the disk. 

* `r1` Internal radius of the disk. 

* `Angle1` Section (in radians) of the disk to be considered in the collision check. 

* `Direction1` `Direction2` Direction (in radians) to which each shape is pointing. 

* `AdjustX` `AdjustY` Measured overlap between the two shapes. Values returned by reference.

#### `public float `[`Clamp`](#namespace_at_utility_1_1_collision_1a2ead0d7cf367180eecf5f54b3e46b2bf)`(float Minimum,float Value,float Maximum)` 

Used to keep a float value within a specified range.

#### Parameters
* `Minimum` Minimum value of the range. 

* `Value` Specified value. 

* `Maximum` Maximum value of the range.

#### `public bool `[`PointInDisk`](#namespace_at_utility_1_1_collision_1a716dad565333216cce69b411dccc61df)`(float X1,float Y1,float X,float Y,float R,float r,float Angle,float Direction)` 

Used to check for collision between a point and a disk.

#### Parameters
* `X1` `Y1` `X` `Y` Coordinates of each shape. 

* `R` External radius of the disk. 

* `r` Internal radius of the disk. 

* `Angle` Section (in radians) of the disk to be considered in the collision check. 

* `Direction` Direction (in radians) to which the disk is pointing.

#### `public bool `[`PointInRectangle`](#namespace_at_utility_1_1_collision_1aebcee1a7daa7b8f62427e4e333d0fe9f)`(float X1,float Y1,float X,float Y,int Width,int Height,float Direction)` 

Used to check for collision between a point and a rectangle.

#### Parameters
* `X1` `Y1` `X` `Y` Coordinates of each shape. 

* `Width` `Height` Dimensions of the rectangle. 

* `Direction` Direction (in radians) to which the rectangle is pointing.

#### `public bool `[`PointInTriangle`](#namespace_at_utility_1_1_collision_1a6c983797093b524146068aa5c7957eaa)`(float X1,float Y1,float X,float Y,int Width,int Height,float Direction)` 

Used to check for collision between a point and an isosceles triangle.

#### Parameters
* `X1` `Y1` `X` `Y` Coordinates of each shape. 

* `Width` `Height` Dimensions of the triangle. 

* `Direction` Direction (in radians) to which the triangle is pointing.

#### `public bool `[`RectangleInRectangle`](#namespace_at_utility_1_1_collision_1a447c1d12735eeb2919ada3fc588f2faa)`(float X1,float Y1,int Width1,int Height1,float Direction1,float X2,float Y2,int Width2,int Height2,float Direction2,float & AdjustX,float & AdjustY)` 

Used to check for collision between a point and a rectangle.

#### Parameters
* `X1` `Y1` `X2` `Y2` Coordinates of each rectangle. 

* `Width1` `Height1` `Width2` `Height2` `Dimensions` of each rectangle. 

* `Direction1` `Direction2` Direction (in radians) to which each rectangle is pointing. 

* `AdjustX` `AdjustY` Measured overlap between the two rectangles. Values returned by reference.

#### `public void `[`RotatePointBy`](#namespace_at_utility_1_1_collision_1aa31b5926e581b7b336c09774c2bba58e)`(float & X1,float & Y1,float CenterX,float CenterY,float Angle)` 

Used to rotate a point around a center point by the specified angle.

#### Parameters
* `X1` `Y1` Coordinates of the point. 

* `CenterX` `CenterY` Coordinates of the center point. 

* `Angle` Direction (in radians) to which the point will be rotated.

# namespace AtUtility::Files 

Functions used to browse directories/files.

## AtUtility::Files Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::vector< std::string > `[`GetDirectoryList`](#namespace_at_utility_1_1_files_1a46a96493b5ffb894067e1143e49fdd3f)`(std::string Path,std::string FileType)`            | Used to return a list of available directories and files at the specified path.

## AtUtility::Files Members

#### `public std::vector< std::string > `[`GetDirectoryList`](#namespace_at_utility_1_1_files_1a46a96493b5ffb894067e1143e49fdd3f)`(std::string Path,std::string FileType)` 

Used to return a list of available directories and files at the specified path.

#### Parameters
* `Path` Path to browse to. 

* `FileType` Optional file type to limit the results to within the directory.

# namespace AtUtility::Lua 

Functions used to execute [Lua](#namespace_at_utility_1_1_lua) scripts.

## AtUtility::Lua Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int `[`ExecuteScript`](#namespace_at_utility_1_1_lua_1a2a9369ef552454fe3773a1dfffae601a)`(lua_State * Lua,std::string Script)`            | Used to execute a [Lua](#namespace_at_utility_1_1_lua) script.
`public int `[`ExecuteFile`](#namespace_at_utility_1_1_lua_1a21e1bebb9c2d7046887f62c4f7a59f4d)`(lua_State * Lua,std::string Location)`            | Used to execute a [Lua](#namespace_at_utility_1_1_lua) script from the specified file.

## AtUtility::Lua Members

#### `public int `[`ExecuteScript`](#namespace_at_utility_1_1_lua_1a2a9369ef552454fe3773a1dfffae601a)`(lua_State * Lua,std::string Script)` 

Used to execute a [Lua](#namespace_at_utility_1_1_lua) script.

#### Parameters
* `[Lua](#namespace_at_utility_1_1_lua)` The [Lua](#namespace_at_utility_1_1_lua) context. 

* `Script` The [Lua](#namespace_at_utility_1_1_lua) script as a string.

#### `public int `[`ExecuteFile`](#namespace_at_utility_1_1_lua_1a21e1bebb9c2d7046887f62c4f7a59f4d)`(lua_State * Lua,std::string Location)` 

Used to execute a [Lua](#namespace_at_utility_1_1_lua) script from the specified file.

#### Parameters
* `[Lua](#namespace_at_utility_1_1_lua)` The [Lua](#namespace_at_utility_1_1_lua) context. 

* `Location` The location of the [Lua](#namespace_at_utility_1_1_lua) script to be executed.

# namespace AtUtility::Renderer 

Functions used to setup OpenGL and render 2D shapes.

## AtUtility::Renderer Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`Clear`](#namespace_at_utility_1_1_renderer_1a2b389035eae9a0d4abd6da650ab45117)`()`            | Clears the renderer.
`public SDL_Cursor * `[`CreateCursorFromData`](#namespace_at_utility_1_1_renderer_1a6127da03a171636ae8fcf5b2c73c5d63)`(Uint8 * Pixels,int Width,int Height)`            | Returns a cursor image in the SDL_Cursor format from an array of pixels.
`public void `[`GetStringSize`](#namespace_at_utility_1_1_renderer_1a120b396ca57c8ca76394d1bfbc48fe6e)`(std::string FontPath,int Size,std::string Text,int & Width,int & Height)`            | Returns the width and height of a rendered string.
`public int `[`GetViewportHeight`](#namespace_at_utility_1_1_renderer_1ae496fc6d78d6ac7de3312ff8c98ada71)`()`            | Returns the height of the OpenGL viewport.
`public int `[`GetViewportWidth`](#namespace_at_utility_1_1_renderer_1a9cdf2a62d6f8449985f64488eae81e55)`()`            | Returns the width of the OpenGL viewport.
`public SDL_Surface * `[`LoadImage`](#namespace_at_utility_1_1_renderer_1a4e9c177cf6fa342a0a91d7f46cde9e92)`(std::string Location)`            | Loads the specified image file and returns it in the SDL_Surface format.
`public void `[`RenderDisk`](#namespace_at_utility_1_1_renderer_1a266dc4bb0d11b03ab93dacbd58d40b2c)`(float TargetX,float TargetY,float OuterRadius,float InnerRadius,float Angle,bool Filled)`            | Renders a 2D disk.
`public void `[`RenderRectangle`](#namespace_at_utility_1_1_renderer_1a856ba3352183690fa50b7869a4c4061e)`(float TargetX,float TargetY,float Width,float Height,bool Filled)`            | Renders a 2D rectangle.
`public void `[`RenderTriangle`](#namespace_at_utility_1_1_renderer_1ab8237e68eaae92cff5fe0cb5d0d7824e)`(float TargetX,float TargetY,float Width,float Height)`            | Renders a 2D isosceles triangle.
`public void `[`Reset`](#namespace_at_utility_1_1_renderer_1ac239cdebba7fdfe83dc0002f8e9733b0)`(GLenum Mode)`            | Resets the renderer.
`public void `[`Rotate`](#namespace_at_utility_1_1_renderer_1a451f3db59d91686eb4cc1ba4e5026cc4)`(GLenum Mode,float Angle,float CenterX,float CenterY)`            | Rotate the renderer.
`public bool `[`SaveScreenshot`](#namespace_at_utility_1_1_renderer_1a0e89322a853856ec823da341ee2e7d35)`(std::string Location)`            | Saves a screenshot in bmp format at the specified location.
`public void `[`Scale`](#namespace_at_utility_1_1_renderer_1a3b47bc3f1adb7803cfe161772b2e7957)`(GLenum Mode,float ScaleX,float ScaleY,float CenterX,float CenterY)`            | Rescale the renderer.
`public void `[`SetClearColor`](#namespace_at_utility_1_1_renderer_1ab4af81164a4ad1585c4d7c59454912dd)`(float R,float G,float B,float A)`            | Sets the clear color of the renderer to the specified RGBA value (0f-1f).
`public void `[`SetClearColor`](#namespace_at_utility_1_1_renderer_1a7a5328929c32759801114fbe70b3efc8)`(int R,int G,int B,int A)`            | Sets the clear color of the renderer to the specified RGBA value (0-255).
`public void `[`SetColor`](#namespace_at_utility_1_1_renderer_1a7a24a31dd8501279d3c4c9c0b2ba0e61)`(float R,float G,float B,float A)`            | Sets the color of the renderer to the specified RGBA value (0f-1f).
`public void `[`SetColor`](#namespace_at_utility_1_1_renderer_1a211b482f0e0ec556c4e1d282deb63e94)`(int R,int G,int B,int A)`            | Sets the color of the renderer to the specified RGBA value (0-255).
`public void `[`Setup2D`](#namespace_at_utility_1_1_renderer_1aeffa3887e296e12738716aef6964ffc2)`(int Width,int Height)`            | Setup the OpenGL context for 2D rendering.
`public void `[`Setup3D`](#namespace_at_utility_1_1_renderer_1a8efeffd4537f41cc03c1370769c72de9)`(int Width,int Height)`            | Setup the OpenGL context for 3D rendering.
`public void `[`SetViewport`](#namespace_at_utility_1_1_renderer_1a56a8c3734f14e00e4c04c7198ec2d127)`(int Width,int Height)`            | Set the OpenGL viewport dimensions.
`public void `[`Who`](#namespace_at_utility_1_1_renderer_1a17d1e165295121fa1f22aef9df274547)`()`            | Outputs OpenGL version information to the console.

## AtUtility::Renderer Members

#### `public void `[`Clear`](#namespace_at_utility_1_1_renderer_1a2b389035eae9a0d4abd6da650ab45117)`()` 

Clears the renderer.

#### `public SDL_Cursor * `[`CreateCursorFromData`](#namespace_at_utility_1_1_renderer_1a6127da03a171636ae8fcf5b2c73c5d63)`(Uint8 * Pixels,int Width,int Height)` 

Returns a cursor image in the SDL_Cursor format from an array of pixels.

#### `public void `[`GetStringSize`](#namespace_at_utility_1_1_renderer_1a120b396ca57c8ca76394d1bfbc48fe6e)`(std::string FontPath,int Size,std::string Text,int & Width,int & Height)` 

Returns the width and height of a rendered string.

#### Parameters
* `FontPath` Path to the font to be used for rendering the text. 

* `Size` Size of the font. 

* `Text` Text to be rendered. 

* `Width` `Height` Calculated width and height of the rendered string. Returned by reference.

#### `public int `[`GetViewportHeight`](#namespace_at_utility_1_1_renderer_1ae496fc6d78d6ac7de3312ff8c98ada71)`()` 

Returns the height of the OpenGL viewport.

#### `public int `[`GetViewportWidth`](#namespace_at_utility_1_1_renderer_1a9cdf2a62d6f8449985f64488eae81e55)`()` 

Returns the width of the OpenGL viewport.

#### `public SDL_Surface * `[`LoadImage`](#namespace_at_utility_1_1_renderer_1a4e9c177cf6fa342a0a91d7f46cde9e92)`(std::string Location)` 

Loads the specified image file and returns it in the SDL_Surface format.

#### `public void `[`RenderDisk`](#namespace_at_utility_1_1_renderer_1a266dc4bb0d11b03ab93dacbd58d40b2c)`(float TargetX,float TargetY,float OuterRadius,float InnerRadius,float Angle,bool Filled)` 

Renders a 2D disk.

#### Parameters
* `TargetX` `TargetY` The coordinates for the rendered disk. 

* `OuterRadius` The outer radius of the disk. 

* `InnerRadius` The inner radius of the disk. 

* `Angle` The section (in radians) of the disk to be rendered. 

* `Filled` If set to true, the rendered disk is filled. If set to false, the rendered disk is hollow.

#### `public void `[`RenderRectangle`](#namespace_at_utility_1_1_renderer_1a856ba3352183690fa50b7869a4c4061e)`(float TargetX,float TargetY,float Width,float Height,bool Filled)` 

Renders a 2D rectangle.

#### Parameters
* `TargetX` `TargetY` The coordinates for the rendered rectangle. 

* `Width` `Height` The dimensions of the rectangle. 

* `Filled` If set to true, the rendered rectangle is filled. If set to false, the rendered rectangle is hollow.

#### `public void `[`RenderTriangle`](#namespace_at_utility_1_1_renderer_1ab8237e68eaae92cff5fe0cb5d0d7824e)`(float TargetX,float TargetY,float Width,float Height)` 

Renders a 2D isosceles triangle.

#### Parameters
* `TargetX` `TargetY` The coordinates for the rendered triangle. 

* `Width` `Height` The dimensions of the triangle.

#### `public void `[`Reset`](#namespace_at_utility_1_1_renderer_1ac239cdebba7fdfe83dc0002f8e9733b0)`(GLenum Mode)` 

Resets the renderer.

#### `public void `[`Rotate`](#namespace_at_utility_1_1_renderer_1a451f3db59d91686eb4cc1ba4e5026cc4)`(GLenum Mode,float Angle,float CenterX,float CenterY)` 

Rotate the renderer.

#### Parameters
* `Mode` glMatrixMode 

* `Angle` The angle by which to rotate the viewport. 

* `CenterX` `CenterY` The center of rotation.

#### `public bool `[`SaveScreenshot`](#namespace_at_utility_1_1_renderer_1a0e89322a853856ec823da341ee2e7d35)`(std::string Location)` 

Saves a screenshot in bmp format at the specified location.

#### Parameters
* `Location` Target location for the screenshot.

#### `public void `[`Scale`](#namespace_at_utility_1_1_renderer_1a3b47bc3f1adb7803cfe161772b2e7957)`(GLenum Mode,float ScaleX,float ScaleY,float CenterX,float CenterY)` 

Rescale the renderer.

#### Parameters
* `Mode` glMatrixMode 

* `ScaleX` `ScaleY` The specified scale for the renderer. 

* `CenterX` `CenterY` The center of the viewport.

#### `public void `[`SetClearColor`](#namespace_at_utility_1_1_renderer_1ab4af81164a4ad1585c4d7c59454912dd)`(float R,float G,float B,float A)` 

Sets the clear color of the renderer to the specified RGBA value (0f-1f).

#### `public void `[`SetClearColor`](#namespace_at_utility_1_1_renderer_1a7a5328929c32759801114fbe70b3efc8)`(int R,int G,int B,int A)` 

Sets the clear color of the renderer to the specified RGBA value (0-255).

#### `public void `[`SetColor`](#namespace_at_utility_1_1_renderer_1a7a24a31dd8501279d3c4c9c0b2ba0e61)`(float R,float G,float B,float A)` 

Sets the color of the renderer to the specified RGBA value (0f-1f).

#### `public void `[`SetColor`](#namespace_at_utility_1_1_renderer_1a211b482f0e0ec556c4e1d282deb63e94)`(int R,int G,int B,int A)` 

Sets the color of the renderer to the specified RGBA value (0-255).

#### `public void `[`Setup2D`](#namespace_at_utility_1_1_renderer_1aeffa3887e296e12738716aef6964ffc2)`(int Width,int Height)` 

Setup the OpenGL context for 2D rendering.

#### `public void `[`Setup3D`](#namespace_at_utility_1_1_renderer_1a8efeffd4537f41cc03c1370769c72de9)`(int Width,int Height)` 

Setup the OpenGL context for 3D rendering.

#### `public void `[`SetViewport`](#namespace_at_utility_1_1_renderer_1a56a8c3734f14e00e4c04c7198ec2d127)`(int Width,int Height)` 

Set the OpenGL viewport dimensions.

#### `public void `[`Who`](#namespace_at_utility_1_1_renderer_1a17d1e165295121fa1f22aef9df274547)`()` 

Outputs OpenGL version information to the console.

# namespace AtUtility::Strings 

Functions used to manipulate strings.

## AtUtility::Strings Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int `[`FindNthOf`](#namespace_at_utility_1_1_strings_1a9cd5799be61e922a11599a979fc3502b)`(int & Occurrence,char Character,const std::string & String)`            | Returns the position of the nth occurrence of a character within the specified string.
`public int `[`FindTotalOf`](#namespace_at_utility_1_1_strings_1a4ebbe3c63df4da9df851adfeca2ce56d)`(char Character,const std::string & String)`            | Returns the total occurrences of a character within the specified string.
`public std::string `[`Separate`](#namespace_at_utility_1_1_strings_1a501bba3deb1b261a77247386647ed110)`(const std::string & String,char Separator,int SubstringNumber)`            | Returns a substring from a character-delimited string, as specified by the parameters.
`public template<>`  <br/>`Type `[`StringTo`](#namespace_at_utility_1_1_strings_1a84344bc7bbd9457411f556d3e774d6c3)`(const std::string & String,char Separator,int SubstringNumber)`            | Converts a string to the specified type.

## AtUtility::Strings Members

#### `public int `[`FindNthOf`](#namespace_at_utility_1_1_strings_1a9cd5799be61e922a11599a979fc3502b)`(int & Occurrence,char Character,const std::string & String)` 

Returns the position of the nth occurrence of a character within the specified string.

#### Parameters
* `Occurrence` Parameter to specify which occurrence to find. 

* `Character` The character to find. 

* `String` The specified string.

#### `public int `[`FindTotalOf`](#namespace_at_utility_1_1_strings_1a4ebbe3c63df4da9df851adfeca2ce56d)`(char Character,const std::string & String)` 

Returns the total occurrences of a character within the specified string.

#### Parameters
* `Character` The character to find. 

* `String` The specified string.

#### `public std::string `[`Separate`](#namespace_at_utility_1_1_strings_1a501bba3deb1b261a77247386647ed110)`(const std::string & String,char Separator,int SubstringNumber)` 

Returns a substring from a character-delimited string, as specified by the parameters.

#### Parameters
* `String` The character-delimited string. 

* `Separator` Optional delimiter character. 

* `SubstringNumber` Optional index of the requested substring within the character-delimited string.

#### `public template<>`  <br/>`Type `[`StringTo`](#namespace_at_utility_1_1_strings_1a84344bc7bbd9457411f556d3e774d6c3)`(const std::string & String,char Separator,int SubstringNumber)` 

Converts a string to the specified type.

#### Parameters
* `String` The string to be converted. 

* `Separator` Optional delimiter character. 

* `SubstringNumber` Optional index of the requested value within a character-delimited string.

# namespace AtUtility::Vectors 

Functions used to operate on std::vector structures.

## AtUtility::Vectors Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public template<>`  <br/>`int `[`FindMaximum`](#namespace_at_utility_1_1_vectors_1af471f8978a886e5b891a445131428fec)`(std::vector< Type > Vector)`            | Finds the maximum value within the specified vector and returns its index.
`public template<>`  <br/>`int `[`FindMinimum`](#namespace_at_utility_1_1_vectors_1acc24628fbd74c4e0aa3d5bb41e0479f3)`(std::vector< Type > Vector)`            | Finds the minimum value within the specified vector and returns its index.

## AtUtility::Vectors Members

#### `public template<>`  <br/>`int `[`FindMaximum`](#namespace_at_utility_1_1_vectors_1af471f8978a886e5b891a445131428fec)`(std::vector< Type > Vector)` 

Finds the maximum value within the specified vector and returns its index.

#### `public template<>`  <br/>`int `[`FindMinimum`](#namespace_at_utility_1_1_vectors_1acc24628fbd74c4e0aa3d5bb41e0479f3)`(std::vector< Type > Vector)` 

Finds the minimum value within the specified vector and returns its index.

Generated by [Moxygen](https://sourcey.com/moxygen)