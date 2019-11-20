# lightdm-qt5-greeter

lightdm-qt5-greeter is a simple frontend for the lightdm displaymanager, written in c++ and qt5.

It has it's roots in the razor project, where it was developed under the name razor-lightdm-greeter. When razor was merged into LXQt it was renamed to lxlightdm-qt5-greeter.

As of september 2015 I have renamed it to qt-lightdm-greeter and cut it's ties to LXQt. This was primarily because LXQt recommends SDDM as its displaymanager and because the application had very little integration with LXQt. 

qt-lightdm-greeter sports a razor-qt logo as a reminder of it's origin.

## Installing

Make sure you have cmake, gcc, qt5 and liblightdm-qt5 (and lightdm) installed on your system

Do
    
```shell
git clone https://github.com/surlykke/lightdm-qt5-greeter.git
cd lightdm-qt5-greeter
mkdir build
cd build
cmake ..
make 
sudo make install
```

## How to enable lightdm-qt5 greeter

Update or insert in(to) your `/etc/lightdm/lightdm.conf`, in the `SeatDefaults` section, this line:

    greeter-session=lightdm-qt5-greeter

## Configure lightdm-qt5-greeter

The file `/etc/lightdm/lightdm-qt5-greeter.conf` allows for a 
few configurations of lightdm-qt5-greeter (background-image, positioning of loginform). 
The configuration options are documented in that file.

