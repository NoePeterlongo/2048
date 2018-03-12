import QtQuick 2.0

Item {
    id: item1
    width: 70
    height: 70

    Rectangle {
        id: rectangle
        x: 15
        y: 8
        width: 70
        height: 70
        //color: "#ffffff"
        color: vueObjetTui.tuileCol
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        id: text1
        x: -94
        y: -55
        width: 70
        height: 70
        //text: qsTr("Text")
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
        text: vueObjetTui.tuileTxt
    }

}
