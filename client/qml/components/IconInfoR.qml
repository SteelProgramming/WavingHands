import QtQuick 2.9

//Implementation of the Button control.
Rectangle {
    id: button

    property bool active: true
    property alias text_color: btnText.color
    property alias text: btnText.text
    property alias fontSizeMode: btnText.fontSizeMode
    property alias source: iIcon.source
    property alias iconVisible: iIcon.visible
    property alias textVisible: btnText.visible

    signal clicked

    gradient: Gradient {
        GradientStop { position: 0.0; color: "#E7FFFF" }
        GradientStop { position: 1.0; color: "#FEE2D6" }
    }

    Image {
        id: iIcon
        anchors.fill: parent;
    }

    LargeText {
        id: btnText
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        height: 0.1 * parent.height
        width: 0.1 * parent.width
        color: "white"
        fontSizeMode: Text.Fit
    }

    //Mouse area to react on click events
    MouseArea {
        anchors.fill: button
        onClicked: {
            if (active) {
                button.clicked();
            }
        }
    }

    function onFinishCreation() {
        console.log("Button.onFinishCreation");
    }

    Component.onCompleted: onFinishCreation();
}