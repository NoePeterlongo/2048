import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    id: window
    visible: true
    width: 600
    height: 680
    color: '#F6E5C2'
    property alias grid: grid
    title: qsTr("2048")

    Rectangle {
        id: rectangle
        width: 430
        height: 430
        color: "yellow"
        anchors.verticalCenterOffset: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Grid {
            id: grid
            x: 92
            y: 252
            width: 415
            height: 415
            anchors.verticalCenterOffset: 0
            spacing: 5
            transformOrigin: Item.Center
            rows: 4
            columns: 4
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Tuile {
                id: tuile1
            }

            Tuile {
                id: tuile
            }

            Tuile {
                id: tuile2
            }

            Tuile {
                id: tuile3
            }

            Tuile {
                id: tuile4
            }

            Tuile {
                id: tuile5
            }

            Tuile {
                id: tuile6
            }

            Tuile {
                id: tuile7
            }

            Tuile {
                id: tuile8
            }

            Tuile {
                id: tuile9
            }

            Tuile {
                id: tuile10
            }

            Tuile {
                id: tuile11
            }

            Tuile {
                id: tuile12
            }

            Tuile {
                id: tuile13
            }

            Tuile {
                id: tuile14
            }

            Tuile {
                id: tuile15
            }
        }
    }

    Text {
        id: text1
        width: 152
        height: 57
        text: qsTr("2048")
        anchors.horizontalCenterOffset: -147
        anchors.top: parent.top
        anchors.topMargin: 43
        anchors.horizontalCenter: parent.horizontalCenter
        font.strikeout: false
        font.italic: true
        font.bold: false
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        fontSizeMode: Text.FixedSize
        font.pixelSize: 57
        style: Text.Sunken
    }

    Rectangle {
        id: rectangle1
        x: 297
        y: 43
        width: 105
        height: 57
        color: "#ffffff"

        Text {
            id: text2
            width: 105
            height: 21
            text: qsTr("Score")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.capitalization: Font.MixedCase
            font.weight: Font.ExtraLight
            font.pixelSize: 17
        }

        Text {
            id: text3
            x: 0
            y: 22
            width: 105
            height: 35
            //text: qsTr("0")
            text: jeu.scoreQML
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 21
        }
    }

    Rectangle {
        id: rectangle2
        x: 410
        y: 43
        width: 105
        height: 57
        color: "#ffffff"
        Text {
            id: text4
            width: 105
            height: 21
            text: qsTr("Record")
            font.weight: Font.ExtraLight
            horizontalAlignment: Text.AlignHCenter
            font.capitalization: Font.MixedCase
            font.pixelSize: 17
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: text5
            x: 0
            y: 22
            width: 105
            height: 35
            text: qsTr("0")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 21
            verticalAlignment: Text.AlignVCenter
        }
    }

    Button {
        id: buttonNouvellePartie
        x: 297
        y: 130
        width: 105
        height: 50
        text: qsTr("Nouvelle partie")
        font.pointSize: 10
        onClicked: jeu.InitialiserPartie()
    }

    Button {
        id: buttonAnnuler
        x: 410
        y: 130
        width: 105
        height: 50
        text: qsTr("Annuler coup")
        font.pointSize: 10
    }
}
