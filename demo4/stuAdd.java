package demo4;



import javax.swing.*;
import javax.swing.border.Border;


import java.sql.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class stuAdd extends JDialog implements ActionListener {
    // 定义需要的swing组件
    JLabel jl1, jl2, jl3, jl4, jl5, jl6;
    JButton jb1, jb2, jb3;
    JTextField jtf1, jtf2, jtf3, jtf4, jtf5, jtf6;
    JPanel jp1, jp2, jp3;

    // 他的父窗口owner 窗口名字 模式窗口or非模式（）
    public stuAdd(Frame owner, String title, boolean model) {
        super(owner, title, model);
        jl1 = new JLabel("stuId");
        jl2 = new JLabel("stuName");
        jl3 = new JLabel("stuSex");
        jl4 = new JLabel("score1");
        jl5 = new JLabel("score2");
        jl6 = new JLabel("score3");

        jtf1 = new JTextField();
        jtf2 = new JTextField();
        jtf3 = new JTextField();
        jtf4 = new JTextField();
        jtf5 = new JTextField();
        jtf6 = new JTextField();

        jb1 = new JButton("添加");
        jb1.addActionListener(this);
        jb2 = new JButton("取消");

        jp1 = new JPanel();
        jp2 = new JPanel();
        jp3 = new JPanel();
        // 设置布局
        jp1.setLayout(new GridLayout(6, 1));
        jp2.setLayout(new GridLayout(6, 1));
        // 添加组件
        jp1.add(jl1);
        jp1.add(jl2);
        jp1.add(jl3);
        jp1.add(jl4);
        jp1.add(jl5);
        jp1.add(jl6);

        jp2.add(jtf1);
        jp2.add(jtf2);
        jp2.add(jtf3);
        jp2.add(jtf4);
        jp2.add(jtf5);
        jp2.add(jtf6);

        jp3.add(jb1);
        jp3.add(jb2);
        this.add(jp1, BorderLayout.WEST);
        this.add(jp2, BorderLayout.CENTER);
        this.add(jp3, BorderLayout.SOUTH);
        // 展现
        this.setSize(350, 300);
        this.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        if (e.getSource() == jb1) {
            // 连接数据库
            Connection conn = null;
            Statement stml = null;
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
                String sql = "insert into stu values(?,?,?,?,?,?)";
                ps = conn.prepareStatement(sql);
                // 给参数赋值
                ps.setString(1, jtf1.getText());
                ps.setString(2, jtf2.getText());
                ps.setString(3, jtf3.getText());
                ps.setString(4, jtf4.getText());
                ps.setString(5, jtf5.getText());
                ps.setString(6, jtf6.getText());
                // 4.执行操作
                ps.executeUpdate();
                this.dispose();// 关闭对话框
            } catch (Exception e2) {
                e2.printStackTrace();
            } finally {
                try {
                    if (rs != null)
                        rs.close();
                    if (ps != null)
                        ps.close();
                    if (conn != null)
                        conn.close();
                } catch (SQLException e1) {
                    e1.printStackTrace();
                }

            }
        }
    }
}
