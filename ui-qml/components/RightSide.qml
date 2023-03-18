import QtQuick 2.15
import QtQuick.Layouts 6.3


ColumnLayout{
    id: right
    spacing: 5
    anchors {
       top: topBar.bottom
       bottom: bottomBar.top
       right: parent.right
       bottomMargin: 3
    }

    width: parent.width * 1/3

    Rectangle {
        id: rightTop
        Layout.alignment: Qt.AlignVCenter
        color: "#222B45"
        radius:14
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.preferredWidth: 50
        Layout.preferredHeight: 37        
         

                      Text{
                            id:utcText
                            anchors {
                               left:rightTop.left
                               top:rightTop.top
                               leftMargin:30
                               topMargin:22
                                      }
                            color:"#72B0C3"
                            text: qsTr("UTC Time :")
                            font.pixelSize: 17
                                      }
                        
                           Rectangle {
                               id: utcRect
                               color: "#2C3755"
                                anchors {
                                        left:utcText.right
                                        top:rightTop.top
                                        leftMargin:90
                                        topMargin:22
                                         }
                              height:25
                              width:120
                              radius:5  
                                       }


                             TextInput {
                                  id: textInput1
                                   anchors {
                                        left:utcText.right
                                        top:rightTop.top
                                        leftMargin:105
                                        topMargin:23
                                        }
                                  text: qsTr("Text Input")
                                  font.pixelSize: 17
                                  color:"#ffffff"
                                          }



                         

                            
                      Text{
                            id:cmdLongi
                            anchors {
                               left:rightTop.left
                               top:rightTop.top
                               leftMargin:28
                               topMargin:58
                                      }
                            color:"#72B0C3"
                            text: qsTr("CMD Longitude:")
                            font.pixelSize: 17
                                      }
                        
                           Rectangle {
                               id: longiRect
                               color: "#2C3755"
                                anchors {
                                        left:cmdLongi.right
                                        top:rightTop.top
                                        leftMargin:50
                                        topMargin:58  
                                         }
                              height:25
                              width:120
                              radius:5  
                                       }

                             TextInput {
                                  id: longiTextIp
                                   anchors {
                                        left:cmdLongi.right
                                        top:rightTop.top
                                        leftMargin:65
                                        topMargin:59
                                        }
                                  text: qsTr("Text Input")
                                  font.pixelSize: 17
                                  color:"#ffffff"
                                          }





                                    
                      Text{
                            id:cmdLati
                            anchors {
                               left:rightTop.left
                               top:rightTop.top
                               leftMargin:28
                               topMargin:90
                                      }
                            color:"#72B0C3"
                            text: qsTr("CMD Latitude:")
                            font.pixelSize: 17
                                      }
                        
                           Rectangle {
                               id: latiRect
                               color: "#2C3755"
                                anchors {
                                        left:cmdLati.right
                                        top:rightTop.top
                                        leftMargin:64
                                        topMargin:94
                                         }
                              height:25
                              width:120
                              radius:5  
                                       }


                             TextInput {
                                  id: latiTextIp
                                   anchors {
                                        left:cmdLati.right
                                        top:rightTop.top
                                        leftMargin:79
                                        topMargin:93
                                        }
                                  text: qsTr("Text Input")
                                  font.pixelSize: 17
                                  color:"#ffffff"
                                          }



                      

                                             
                      Text{
                            id:cmdAlti
                            anchors {
                               left:rightTop.left
                               top:rightTop.top
                               leftMargin:28
                               topMargin:130
                                      }
                            color:"#72B0C3"
                            text: qsTr("CMD Altitude:")
                            font.pixelSize: 17
                                      }
                        
                           Rectangle {
                               id: altiRect
                               color: "#2C3755"
                                anchors {
                                        left:cmdAlti.right
                                        top:rightTop.top
                                        leftMargin:64
                                        topMargin:130
                                         }
                              height:25
                              width:120
                              radius:5  
                                       }


                             TextInput {
                                  id: altiTextIp
                                   anchors {
                                        left:cmdAlti.right
                                        top:rightTop.top
                                        leftMargin:79
                                        topMargin:129
                                        }
                                  text: qsTr("Text Input")
                                  font.pixelSize: 17
                                  color:"#ffffff"
                                          }










                    }



    ColumnLayout {
        id: rightBottom
        spacing: 5
        Layout.alignment: Qt.AlignLeft
        Layout.preferredHeight: 90

        Rectangle {
            id: map
            Layout.alignment: Qt.AlignVCenter
            radius:14
            color: "#222B45"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 50
            Layout.preferredHeight: 50


             Text{
                         id:maptext
                          anchors {
                              left:map.left
                              top:map.top
                              leftMargin:11
                              topMargin:12
                                    }
                         color:"#ffffff"
                         text: qsTr("Map")
                         font.pixelSize: 19
                          }


                    Rectangle {
                             id: mapRect
                                anchors {
                                   left:map.left
                                   top:map.top
                                   leftMargin:11
                                   topMargin:43
                                         }
                                  radius:14
                                  color: "#72B0C3"
                                  height: 170
                                  width: 400


                                      Image {
                                               id:location
                      
                                               width: 47
                                               height: 47
                                               source: "qrc:///images/location.jpg"
                                               fillMode: Image.PreserveAspectFit
                    
                                               anchors{
                                                   left:mapRect.left
                                                   top:mapRect.top
                              
                                                        }
      
                                               }

                                  }

        }

        Rectangle {
            id: telemetry
            Layout.alignment: Qt.AlignVCenter
            radius:14
            color: "#222B45"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 50
            Layout.preferredHeight: 50

                    Text{
                         id:telControlHeading
                          anchors {
                              left:telemetry.left
                              top:telemetry.top
                              leftMargin:11
                              topMargin:14
                                    }
                         color:"#ffffff"
                         text: qsTr("Telemetry Control")
                         font.pixelSize: 19
                          }


                    Rectangle {
                             id: telemetryRect
                                anchors {
                                   left:telemetry.left
                                   top:telemetry.top
                                   leftMargin:11
                                   topMargin:43
                                         }
                                  radius:14
                                  color: "#2A3451"
                                  height: 170
                                  width: 400
                                  }

        
         }




             


        }
    }

