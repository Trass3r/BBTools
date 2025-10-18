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


## Cheat Mode

The game contains a hidden cheat mode and map editor that can be enabled by patching the executable.

**Cheat Mode Flag:** `dword_4842A0` (global variable)
- Address: `0x004842A0`
- Type: `int`
- Value: `0` = disabled, `1` = enabled

**Detection Code:**
```asm
.text:0040C49B A1 A0 42 48 00                       mov     eax, dword_4842A0
.text:0040C4A0 85 C0                                test    eax, eax
.text:0040C4A2 74 18                                jz      short loc_40C4BC
.text:0040C4A4 6A 02                                push    2
.text:0040C4A6 B9 70 5B 5C 00                       mov     ecx, offset unk_5C5B70
.text:0040C4AB 6A 06                                push    6
.text:0040C4AD 68 76 02 00 00                       push    276h
.text:0040C4B2 68 14 6E 48 00                       push    offset aCheat   ; "CHEAT"
.text:0040C4B7 E8 A4 40 02 00                       call    DrawString
```

The `jz` (jump if zero) instruction at `0x0040C4A2` checks if `dword_4842A0` equals 0.

### Enabling Cheat Mode

1. Open `beasts.exe` in a hex editor
2. Navigate to address `0x004842A0`
3. Change value from `00 00 00 00` to `01 00 00 00`
4. Save the patched executable

**Or in IDA Pro:**
Rename dword_4842A0 to cheat_mode and set value equal to 1. Apply patches to beasts.exe 

When cheat mode is enabled, the text **"CHEAT"** appears in the top-right corner of the screen during gameplay.


| Effect                          | Action         |
|---------------------------------|----------------|
| Unlimited gold                  | [G]            |
| Duplicate last created object   | [C]            |
| Remove fog of war               | [Ctrl] + [F6]  |

# TODO
+ Sounds files (ambient and speach)
+ Drawing info of objects
