package demo4;

import javax.swing.*;
import java.util.*;
import java.sql.*;
import java.awt.*;
import java.awt.Event;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Test2 extends JFrame implements ActionListener {
    // rowData用来存放行数据
    // columnNames用来存放列名

    JTable jt ;
    JScrollPane jsp ;

    JPanel jp1, jp2;
    JLabel jl1;
    JButton jb1, jb2, jb3, jb4;
    JTextField jtf;
    stuModel1 sm = new stuModel1();// 防止内存泄漏

    public static void main(String[] args) {
        Test2 test = new Test2();
    }

    public Test2() {

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
        jb2.addActionListener(this);
        jb3 = new JButton("修改");
        jb3.addActionListener(this);
        jb4 = new JButton("删除");
        jb4.addActionListener(this);
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
            String name = this.jtf.getText().trim();
            String sql = "select* from stu where stuName='" + name + "'";
            if (name.equals(""))
                sql = "";
            sm = new stuModel1(sql);
            jt.setModel(sm);
        }
        // 当用户点击廷加
        else if (e.getSource() == jb2) {
            stuAdd sa = new stuAdd(this, "添加学生", false);// 父窗口 注意true与false区别

            sm = new stuModel1();
            jt.setModel(sm);
        } else if (e.getSource() == jb4) {
            // 返回用户点上的行，要是没选择返回-1
            int rowNum = this.jt.getSelectedRow();
            if (rowNum == -1) {
                // 提示
                JOptionPane.showMessageDialog(this, "请选择一行");
                return;
            }
            // 得到学生编号
            String stuId = (String) sm.getValueAt(rowNum, 0);
            System.out.println("id=" + stuId);
            // 连接数据库完成删除
            Connection conn = null;
            ResultSet rs = null;
            PreparedStatement ps = null;
            String driver="com.mysql.cj.jdbc.Driver";
            //这里是我的数据库的信息
            String url="jdbc:mysql://localhost:3306/studentmanagement?&useSSL=false&serverTimezone=UTC";
            String user="root";
            String password="123456";
            // 连接数据库
            try {
                // 1.加载驱动
                Class.forName(driver);
                //2.、
                conn = DriverManager.getConnection(url, user, password);
                String sql = "delete from stu where stuId=?";
                ps = conn.prepareStatement(sql);
                ps.setString(1, stuId);

                // 4.执行操作
                ps.executeUpdate();
            } catch (Exception e2) {
                e2.printStackTrace();
            } finally {

                sm = new stuModel1();
                jt.setModel(sm);
            }
        } else if (e.getSource() == jb3) {
            // 用户希望修改
            int rowNum = this.jt.getSelectedRow();
            if (rowNum == -1) {
                // 提示
                JOptionPane.showMessageDialog(this, "请选择一行");
                return;
            }
            // 显示修改对话框
            new stuUp(this, "修改", true, sm, rowNum);
            sm = new stuModel1();
            jt.setModel(sm);
        }

    }

}