This project aims at providing a m-in-one package for those who want to try a new networking protocol, the Named Data Networking (NDN), with their IoT apps on constrained devices, e.g., Nordic nRF58240 boards. Here "m" stands for the following 4 parts, from bottom to top: 

1) communication adapation layer, which handels different communicate mediums with the support from operating system (like RIOT), software development kit (like Nordic SDK), or even the raw device drivers

2) basic NDN layer, which offers basic networking layer functionalities, including the basic security support, following the latest NDN specification

3) application support layer, which includes some useful buliding blocks to NDN applications, such as security bootstraping, service discover as well as access control.

4) an example application, where two parties are invovled: a network controller (runs on a android phone) and two devices (Nordic nRF58240 boards).

The first 3 parts together make the NDN-Lite library, while the example application, as a reference, shows how to develop a simple application with the NDN-Lite library. Details of NDN-Lite library and the example applition can be found in: 


Here follows a step-by-step instruction on how to compile the whole package and how to run the example application with the NDN-Lite library:
