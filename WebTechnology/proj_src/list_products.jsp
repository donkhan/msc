<%@ page import="javax.naming.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.*" %>
<%@ page import="javax.sql.*" %>
<%@ page import="org.h2.jdbcx.JdbcDataSource" %>

<%
    String uuid = request.getParameter("uuid");
    String query = request.getParameter("query");
    String product_id = request.getParameter("product_id");
    if(product_id == null) product_id = "";

    Context ctx = new InitialContext();
    Context initCtx  = (Context) ctx.lookup("java:/comp/env");
    DataSource ds = (DataSource) initCtx.lookup("jdbc/MyLocalDB");
    Connection con = ds.getConnection();;
    PreparedStatement stmt;
    ResultSet rs;
%>

<br><br><br>
<TABLE align="center">
   <TR><TH border=1>ID</TH><TH border=1>Name</TH><TH border=1>Category</TH><TH border=1>Price</TH></TR>
        <%
            try {
                 System.out.println(query);
                 stmt = con.prepareStatement(query);
                 System.out.println("PID " + product_id);
                 if(!product_id.equals("")){
                    stmt.setString(1,product_id);
                 }

                 rs = stmt.executeQuery();
                 while (rs.next()) {
        %>
   <TR>
                      <TD border=1> <%= rs.getString(1) %> </TD>
                      <TD border=1> <%= rs.getString(2) %> </TD>
                      <TD border=1> <%= rs.getString(3) %> </TD>
                      <TD border=1> <%= rs.getString(4) %> </TD>
                      <TD border=1>
                        <form action="/sample/editproduct.jsp" method="get">
                        <input type="hidden" name="uuid" value="<% out.print(uuid); %>" >
                        <input type="hidden" name="product_id" value="<% out.print(rs.getString(1)); %>" >
                        <button type="submit" formaction="/prod/editproduct.jsp">Edit</button>
                        </form>
                      </TD>

                      <TD border=1>
                         <form action="/sample/deleteproduct.jsp" method="get">
                         <input type="hidden" name="uuid" value="<% out.print(uuid); %>" >
                         <input type="hidden" name="product_id" value="<% out.print(rs.getString(1)); %>" >
                         <button type="submit" formaction="/prod/deleteproduct.jsp">Delete</button>
                         </form>
                      </TD>
   </TR>
        <%
                 }
        %>
</TABLE>
        <%
            } catch(Throwable t){
                t.printStackTrace();
            }
            finally {
                 if (con!=null) { con.close(); }
            }
        %>