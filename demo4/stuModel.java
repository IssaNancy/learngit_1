package com.test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Vector;

import javax.swing.table.*;

public class stuModel extends AbstractTableModel {
    Vector rowData, columnNames;
    Connection ct = null;
    ResultSet rs = null;
    PreparedStatement ps = null;

    public stuModel(String sql) {
        columnNames = new Vector();
        columnNames.add("学号");
        columnNames.add("名字");
        columnNames.add("性别");
        columnNames.add("成绩1");
        columnNames.add("成绩2");
        columnNames.add("成绩3");
        //
        rowData = new Vector();// 可以存放多行
        String driver="com.mysql.cj.jdbc.Driver";
        //这里是我的数据库的信息
        String url="jdbc:mysql://localhost:3306/studentmanagement?&useSSL=false&serverTimezone=UTC";
        String user="root";
        String password="123456";
        try {// 1.加载驱动
            Class.forName(driver);
            //2.、
            ct= DriverManager.getConnection(url, user, password);
            ps = ct.prepareStatement(sql);
            rs = ps.executeQuery();
            while (rs.next()) {
                Vector hang = new Vector();
                hang.add(rs.getString(1));
                hang.add(rs.getString(2));
                hang.add(rs.getString(3));
                hang.add(rs.getInt(4));
                hang.add(rs.getString(5));
                hang.add(rs.getString(6));
                // 加入到rowData
                rowData.add(hang);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (rs != null)
                    rs.close();
                if (ps != null)
                    ps.close();
                if (ct != null)
                    ct.close();
            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }
    }

    @Override
    public int getRowCount() {// 多少行
        return this.rowData.size();
    }

    @Override
    public int getColumnCount() {// 多少列
        // TODO Auto-generated method stub
        return this.columnNames.size();
    }

    @Override
    public Object getValueAt(int row, int column) {
        return ((Vector) this.rowData.get(row)).get(column);
    }
}