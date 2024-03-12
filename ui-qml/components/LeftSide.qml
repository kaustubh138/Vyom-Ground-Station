import QtQuick 2.15
import QtQuick.Layouts 6.3
import "./Charts"



ColumnLayout{
    id: leftSide

    spacing: 5
    width: parent.width * 2/3 - 2


    anchors {   
       top: topBar.bottom
       bottom: bottomBar.top
       left: parent.left
       bottomMargin: 3
    }

    Rectangle {
        id: headingBar
        Layout.alignment: Qt.AlignVCenter
        color: "#222B45"
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.preferredWidth: 50
        Layout.preferredHeight: 5
   
           
           Image {
                        id: logo
                      
                       width: 47
                       height: 47
                        source: "qrc:///images/logo.png"
                        fillMode: Image.PreserveAspectFit
                    
                         anchors{
                              left:headingBar.left
                              top:headingBar.top
                              
                               }
      
                    }
                     
                   
               
                    Text{
                         id:cansat
                          anchors {
                              left:headingBar.left
                              top:headingBar.top
                              leftMargin:47
                              topMargin:9
                                    }
                         color:"#ffffff"
                         text: qsTr("CANSAT")
                         font.pixelSize: 24
                          }

              

                   Text{
                         id:state
                          anchors {
                              left:cansat.left
                              top:headingBar.top
                              leftMargin:150
                              topMargin:15
                                    }
                         color:"#C5B2B2"
                         text: qsTr("State : ")
                         font.pixelSize: 18
                          }


                   
                   Text{
                         id:preLaunch
                          anchors {
                              left:cansat.left
                              top:headingBar.top
                              leftMargin:200
                              topMargin:15
                                    }
                         color:"#C5B2B2"
                         text: qsTr(" Prelaunch ")
                         font.pixelSize: 18
                          }



                   Text{
                         id:healthyPac
                          anchors {
                              left:cansat.left
                              top:headingBar.top
                              leftMargin:410
                              topMargin:15
                                    }
                         color:"#C5B2B2"
                         text: qsTr(" Healthy packets : ")
                         font.pixelSize: 18
                          }


                     Text{
                         id:healthyPacCount
                          anchors {
                              left:cansat.left
                              top:headingBar.top
                              leftMargin:550
                              topMargin:15
                                    }
                         color:"green"
                         text: qsTr("")
                         font.pixelSize: 18
                          }
                           


                     Text{
                         id:corruptPac
                          anchors {
                              left:cansat.left
                              top:headingBar.top
                              leftMargin:610
                              topMargin:15
                                    }
                         color:"#C5B2B2"
                         text: qsTr("Corrupted packets :  ")
                         font.pixelSize: 18
                          }

                        Text{
                         id:corruptPacCount
                          anchors {
                              left:cansat.left
                              top:headingBar.top
                              leftMargin:770
                              topMargin:15
                                    }
                         color:"red"
                         text: qsTr("")
                         font.pixelSize: 18
                          }











    }

    Rectangle {
        id: graphSection
        Layout.alignment: Qt.AlignVCenter
        color: "#222B45"
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.preferredWidth: 50
        Layout.preferredHeight: 64

        GridLayout {
            anchors.fill: parent
            columns: 2

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 34

                TempChart {

                           }
                  }

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 34

                AltitudeChart {

                              }
                  }

            Item  {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 34


                VoltageChart {

                              }
                   }

            Item  {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 34


                Yaw {

                              }
                   }
                    Item {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.preferredWidth: 50
                        Layout.preferredHeight: 34

                        Pitch {

                               }
                          }


                
                  

             Rectangle {
                 id: ipSection
                 Layout.alignment: Qt.AlignVCenter
                 color: "#222B45"
                 Layout.fillHeight: true
                 Layout.fillWidth: true
                 Layout.preferredWidth: 50
                 Layout.preferredHeight: 20
                 radius:14

                 Text{
                     id:fsw
                     anchors {
                         left:ipSection.left
                         top:ipSection.top
                         leftMargin:28
                         topMargin:22
                      }
                     color:"#72B0C3"
                     text: qsTr("FSW State:")
                     font.pixelSize: 14
                      }


                         Rectangle {
                     id: fswRect
                     color: "#2C3755"
                     anchors {
                             left:fsw.right
                             top:ipSection.top
                             leftMargin:87
                             topMargin:22
                                  }
                                  height:25
                                  width:120
                                  radius:5  

                     }

                     
                                   TextInput {
                         id: textInput1
                         anchors {
                             left:fsw.right
                             top:ipSection.top
                             leftMargin:105
                             topMargin:25
                                  }
                         text: qsTr("Text Input")
                         font.pixelSize: 14
                         color:"#ffffff"
                              }

                    
                 Text{
                     id:sensCalib
                     anchors {
                         left:ipSection.left
                         top:ipSection.top
                         leftMargin:28
                         topMargin:58
                              }
                      color:"#72B0C3"
                     text: qsTr("Sensor Calibaration:")
                     font.pixelSize: 14
                      }

                      
                         Rectangle {
                              id: sensRect
                              color: "#2C3755"
                              anchors {
                                    left:fsw.right
                                    top:ipSection.top
                                    leftMargin:87
                                    topMargin:58
                                      }
                                  height:25
                                  width:120
                                  radius:5
                                    }
                                   TextInput {
                                     id: sensText
                                     anchors {
                                        left:fsw.right
                                        top:ipSection.top
                                        leftMargin:105
                                        topMargin:60
                                              }
                                   text: qsTr("Text Input")
                                   font.pixelSize: 14
                                   color:"#ffffff"
                                               }


                            
                 Text{
                     id:xbeePort
                     anchors {
                         left:ipSection.left
                         top:ipSection.top
                         leftMargin:28
                         topMargin:90
                              }
                      color:"#72B0C3"
                     text: qsTr("XBee Port:")
                     font.pixelSize: 14
                      }
                    
                          
                          
                         Rectangle {
                              id: portRect
                              color: "#2C3755"
                              anchors {
                                    left:fsw.right
                                    top:ipSection.top
                                    leftMargin:87
                                    topMargin:90
                                      }
                                  height:25
                                  width:120
                                  radius:5
                                    }
                                   TextInput {
                                     id: portText
                                     anchors {
                                        left:fsw.right
                                        top:ipSection.top
                                        leftMargin:105
                                        topMargin:93
                                              }
                                   text: qsTr("Text Input")
                                   font.pixelSize: 14
                                   color:"#ffffff"
                                               }




                 Text{
                     id:chooseFile
                     anchors {
                         left:ipSection.left
                         top:ipSection.top
                         leftMargin:28
                         topMargin:122
                              }
                      color:"#72B0C3"
                     text: qsTr("Choose File:")
                     font.pixelSize: 14
                      }
                           
                              
                         Rectangle {
                              id: chooseRect
                              color: "#2C3755"
                              anchors {
                                    left:fsw.right
                                    top:ipSection.top
                                    leftMargin:87
                                    topMargin:122
                                      }
                                  height:25
                                  width:120
                                  radius:5
                                    }
                                   TextInput {
                                     id: chooseText
                                     anchors {
                                        left:fsw.right
                                        top:ipSection.top
                                        leftMargin:105
                                        topMargin:125
                                              }
                                   text: qsTr("Text Input")
                                   font.pixelSize: 14
                                   color:"#ffffff"
                                               }


                                
                                
                                }



                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                            
                  
                         


                              



    }                                 //rect
}                                     //colm layout

}


