
### A few notes:


### Intro:

The overall goal of my changes to the keyboard layout configuration was to ensure an identical 
set of characters for the most frequently used actions when working with text or code across 
different operating systems. I have to work simultaneously on macOS, Windows, and Linux, 
which use different key combinations for Cut, Copy, Paste, Undo, and Redo operations. I didn't 
create the typical Linux combination of LShift+LCtrl+FunctionKey because I very rarely work 
with it outside of a shell, but this can easily be done by adding an ifelse condition to each 
case.

### The language:

I also needed to implement switching between language layouts in the operating system 
and layers on the keyboard. The second language I use is Russian, which has 33 characters, 
so I needed to create a separate layer with a full layout for it. I spent some time 
researching this, and from my perspective, the most consistent and reliable way to switch 
was to use the LCtrl+LShift+N key combinations across all operating systems, where N=1 for 
English and N=2 for Russian. Attempts to find a compromise with traditional combinations 
were unsuccessful. Manufacturers are convinced that their options are the best and don't
offer very broad customization possibilities. Also, there's no way to get information 
about the current layout from the operating system to decide which layer to switch to, so 
I took the current layer as the starting point in this process. If it equals 0 (i.e., English), 
then switch to layer 1 (i.e., Russian). The system layout also needs to be switched to Russian. 
If it's any other layer, then switch to English, and the system layout to English as well.

Ultimately, I had to resort to using third-party software to enable switching the system 
language layout on macOS according to my desired scheme. This software is called Hammerspoon, 
and it allows for quite flexible remapping and assignment of keys or combinations for various
system functions. Here is the necessary configuration: 

```
hs.hotkey.bind({"ctrl", "shift"}, "1", function()
    hs.keycodes.setLayout("U.S.")
end)

hs.hotkey.bind({"ctrl", "shift"}, "2", function()
    hs.keycodes.setLayout("Russian – PC")
end)
```

You can download the software and view the documentation if needed here: 

```
  https://www.hammerspoon.org/
```

Switch the remote to a different preconfigured SSH key:
- `git remote set-url origin git@github.com-key2:tpaktop77/oryx-with-custom-qmk.git`

### The OSSM

```
  https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum
```
