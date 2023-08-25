# Data Link Protocol

This project was carried out within the scope of the Computer Networks course. The goal was to implement and test a data communication protocol and the final objective was to transfer a file between two machines via a serial port cable.

Grade: 17.8/18


## Instructions

1. Download a virtual serial port.
2. Compile the code with
```gcc main.c -o main linklayer.c```
4. Open the virtual serial port and run the code in two different terminals:
   
	Terminal 1:
	```./main /dev/ttyS0 rx <newfilename>```

	Terminal 2:
	```./main /dev/ttyS1 tx <filename>```

## Credits

Francisco Câmara

Pedro Duarte
 
