import QtQuick 2.0

Item {

    //Cet objet correspond à une case du plateau du 2048.
    //Ses attributs sont la valeur de la case et la couleur de la case

    id: item1
    width: 100
    height: 100

    property string valeur: qsTr("Text")
    property string couleur: qsTr("#F4CA99")

    Rectangle {
        id: rectangle
        x: 15
        y: 8
        width: 100
        height: 100
        color: couleur
        radius: 10
        //color: vueObjetTui.tuileCol
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        id: text1
        x: -94
        y: -55
        width: 100
        height: 100
        text: valeur
        font.strikeout: false
        font.underline: false
        font.italic: false
        font.bold: true
        font.family: "Arial"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 25

    }

}
