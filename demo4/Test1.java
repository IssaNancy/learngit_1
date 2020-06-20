package demo4;



import javax.swing.*;
import java.util.*;
import java.sql.*;
import java.awt.*;
import java.awt.Event;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Test1 extends JFrame implements ActionListener {
    // rowData用来存放行数据
    // columnNames用来存放列名

    JTable jt = null;
    JScrollPane jsp = null;

    JPanel jp1, jp2;
    JLabel jl1;
    JButton jb1, jb2, jb3, jb4;
    JTextField jtf;
    stuModel1 sm;

    public static void main(String[] args) {
        Test1 test = new Test1();
    }

    public Test1() {

        // jt=new JTable(rowData,columnNames);
        // 初始化
        jp1 = new JPanel();
        jtf = new JTextField(10);
        jb1 = new JButton("查询");
        jb1.addActionListener(this);
        jl1 = new JLabel("请输入名字");
        jp1.add(jl1);
        jp1.add(jtf);
        jp1.add(jb1);
        // 初始化下面的
        jp2 = new JPanel();
        jb2 = new JButton("添加");
        jb3 = new JButton("修改");
        jb4 = new JButton("删除");
        jp2.add(jb2);
        jp2.add(jb3);
        jp2.add(jb4);
        // 创建一个数据模型对象
        // 初始化
        jt = new JTable(sm);
        jsp = new JScrollPane(jt);
        // 把jsp放入到JFrame
        this.add(jsp);
        this.add(jp1, "North");
        this.add(jp2, "South");

        this.setSize(400, 300);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub
        if (e.getSource() == jb1) {
            System.out.println("用户希望被查询");
        }
        String name = this.jtf.getText().trim();
        String sql = "select* from stu where stuName='" + name + "'";
        // String sql="select* from stu";
        sm = new stuModel1(sql);
        //
        jt.setModel(sm);

    }
}