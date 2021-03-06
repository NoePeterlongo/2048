import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {

    // On définit d'abord la taille de la fenêtre et sa couleur

    id: window
    visible: true
    width: 600
    height: 680
    color: '#F6E5C2'
    property alias grid: grid
    title: qsTr("2048")


    Rectangle {

        //Définition du rectangle dans lequel on place la grille de tuile représentant le plateau de jeu

        id: rectangle
        width: 430
        height: 430
        color: "#E6B278"
        radius: 10
        anchors.verticalCenterOffset: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Grid {

            //Grille de tuile représentant le plateau. Pour les touches du clavier, le focus est fait sur cette grille

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
            focus : true
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Keys.onPressed: {
              switch (event.key) {
                case Qt.Key_Up:
                  jeu.mvmtHaut();
                  break;
                case Qt.Key_Down:
                  jeu.mvmtBas();
                  break;
                case Qt.Key_Left:
                  jeu.mvmtGauche();
                  break;
                case Qt.Key_Right:
                  jeu.mvmtDroite();
                  break;
              }
            }

            Tuile {
                id: tuile1
                valeur: jeu.plateauQML[0]
                couleur: jeu.colorQML[0]
            }

            Tuile {
                id: tuile
                valeur: jeu.plateauQML[1]
                couleur: jeu.colorQML[1]
            }

            Tuile {
                id: tuile2
                valeur: jeu.plateauQML[2]
                couleur: jeu.colorQML[2]
            }

            Tuile {
                id: tuile3
                valeur: jeu.plateauQML[3]
                couleur: jeu.colorQML[3]
            }

            Tuile {
                id: tuile4
                valeur: jeu.plateauQML[4]
                couleur: jeu.colorQML[4]
            }

            Tuile {
                id: tuile5
                valeur: jeu.plateauQML[5]
                couleur: jeu.colorQML[5]
            }

            Tuile {
                id: tuile6
                valeur: jeu.plateauQML[6]
                couleur: jeu.colorQML[6]
            }

            Tuile {
                id: tuile7
                valeur: jeu.plateauQML[7]
                couleur: jeu.colorQML[7]
            }

            Tuile {
                id: tuile8
                valeur: jeu.plateauQML[8]
                couleur: jeu.colorQML[8]
            }

            Tuile {
                id: tuile9
                valeur: jeu.plateauQML[9]
                couleur: jeu.colorQML[9]
            }

            Tuile {
                id: tuile10
                valeur: jeu.plateauQML[10]
                couleur: jeu.colorQML[10]
            }

            Tuile {
                id: tuile11
                valeur: jeu.plateauQML[11]
                couleur: jeu.colorQML[11]
            }

            Tuile {
                id: tuile12
                valeur: jeu.plateauQML[12]
                couleur: jeu.colorQML[12]
            }

            Tuile {
                id: tuile13
                valeur: jeu.plateauQML[13]
                couleur: jeu.colorQML[13]
            }

            Tuile {
                id: tuile14
                valeur: jeu.plateauQML[14]
                couleur: jeu.colorQML[14]
            }

            Tuile {
                id: tuile15
                valeur: jeu.plateauQML[15]
                couleur: jeu.colorQML[15]
            }
        }

        Rectangle {

            //Affichage du game over en fin de partie

            id: gameOver
            color: "#80fd2727"
            radius: 20
            anchors.fill: parent
            visible: jeu.gameOverVisibleQML;

            Text {
                id: gameOverText
                color: "#c6c6c6"
                text: qsTr("Game Over")
                font.capitalization: Font.AllUppercase
                font.bold: true
                rightPadding: 30
                leftPadding: 30
                topPadding: 0
                fontSizeMode: Text.FixedSize
                wrapMode: Text.NoWrap
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 50
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

        //Zone d'affichage du score

        id: rectangle1
        x: 297
        y: 43
        width: 105
        height: 57
        color: "#f4ca99"
        radius: 5
        anchors.horizontalCenterOffset: 39
        anchors.horizontalCenter: parent.horizontalCenter

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

        //Zone d'affichage du record

        id: rectangle2
        x: 410
        y: 43
        width: 105
        height: 57
        color: "#f4ca99"
        radius: 5
        anchors.horizontalCenterOffset: 185
        anchors.horizontalCenter: parent.horizontalCenter
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
            text: jeu.meilleurScoreQML
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 21
            verticalAlignment: Text.AlignVCenter
        }
    }

    // Positionnement des boutons et affectation de leurs fonctions

    Button {
        id: buttonNouvellePartie
        x: 211
        y: 130
        width: 105
        height: 50
        text: qsTr("Nouvelle partie")
        anchors.horizontalCenterOffset: -36
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 10
        onClicked: {
            grid.focus = true;
            jeu.initialiserPartie();
        }
    }

    Button {
        id: buttonAnnuler
        x: 327
        y: 130
        width: 105
        height: 50
        text: qsTr("Annuler coup")
        anchors.horizontalCenterOffset: 80
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 10
        onClicked: {
            grid.focus = true;
            jeu.annulerCoup();
        }
    }

    Button {
        id: buttonCoupSuivant
        x: 447
        y: 130
        width: 105
        height: 50
        text: qsTr("Coup suivant")
        anchors.horizontalCenterOffset: 199
        anchors.horizontalCenter: parent.horizontalCenter
        leftPadding: 8
        bottomPadding: 6
        focusPolicy: Qt.ClickFocus
        font.pointSize: 10
        onClicked: {
            grid.focus = true;
            jeu.annulerCoup(false);
        }
    }
}
