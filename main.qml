import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480

    Button{
        id:loadUrl
        text: "测试加载url"
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        onClicked: {
            //调用C++ 的方法
            $SigDispatcher.loadUrl();
        }
    }
    Button{
        id:msgQueue
        text: "消息队列"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: loadUrl.right
        anchors.leftMargin: 10
        onClicked: {
            //调用C++ 的方法
            $SigDispatcher.msgQueueSend("hello world");
        }
    }
}
