<%@ page import="javax.naming.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.*" %>
<%@ page import="javax.sql.*" %>
<%@ page import="org.h2.jdbcx.JdbcDataSource" %>

<html>
<head>
<title>Product Management System</title>
</head>
<body bgcolor=white>


<body>

    <%
        String name = request.getParameter("name");
        String password = request.getParameter("password");
        System.out.println("name = " + name + " pw = " + password);
        Context ctx = new InitialContext();

        Context initCtx  = (Context) ctx.lookup("java:/comp/env");
        DataSource ds = (DataSource) initCtx.lookup("jdbc/MyLocalDB");

        Connection con = null;
        PreparedStatement pstmt;
        PreparedStatement stmt;
        try {
             con = ds.getConnection();
             String uuid=UUID.randomUUID().toString();
             con.setAutoCommit(false);
             String query = "select * from customers where name = ? and password = ?";
             System.out.println(query);
             stmt = con.prepareStatement(query);
             stmt.setString(1,name);
             stmt.setString(2,password);
             ResultSet rs = stmt.executeQuery();
             rs.next();
             int i = -1;
             while(rs.next()){
                i = i + 1;
             }
             i = 0;
             rs.close();
             System.out.println(i);
             if(i == 0){
                pstmt = con.prepareStatement("UPDATE CUSTOMERS " +
                                     "SET uuid = ? " +
                                     "WHERE NAME = ?");
                         pstmt.setString(1, uuid);
                         pstmt.setString(2, name);
                         pstmt.executeUpdate();
                con.commit();
                pstmt.close();
                System.out.println("Redirecting to home page");
                response.sendRedirect("/sample/home.jsp?uuid="+uuid);
             }
         } catch(Throwable t){
            t.printStackTrace();
            response.sendRedirect("login.html");
         }
         finally {
             if (con!=null) { con.close(); }
         }
    %>

</body>
</html>
