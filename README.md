# BBTools
Collection of tools for Beasts and Bumpkins

# MAPViewer
MAPViewer is a tool to visualize the mission and savegame files.
![MapViewer](https://i.imgur.com/eqvXmtd.png)

# SpriteViewer
![SpriteViewer](https://i.imgur.com/u2vPSvO.png)

# MAP/SAV file structure
| Data type                      | Name               |
|--------------------------------|--------------------|
| char[3]                        | signature          |
| char[5]                        | version            |
| char[64]                       | mission_name       |
| byte                           | size_x             |
| byte                           | size_y             |
| MapTile[size_x][size_y]        | tiles              |
| int                            | ptr_to_objects_arr |
| int                            | ptr_to_smth2_arr   |
| int                            | size_of_objects_arr|
| MapObject[size_of_objects_arr] | objects            |

# TODO
+ Sounds files (ambient and speach)
+ Drawing info of objects
