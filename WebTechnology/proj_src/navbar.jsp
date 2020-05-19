<%
    String uuid = request.getParameter("uuid");
    System.out.println("Nav Bar " + uuid);
%>

<div class="navbar">
   <a href=home.jsp?uuid="<% out.print(uuid); %>" >Home</a>
   <a href=viewproducts.jsp?uuid="<% out.print(uuid); %>" >View Products</a>
   <a href=addproduct.jsp?uuid="<% out.print(uuid); %>" >Add Product</a>
   <a href=searchproduct.jsp?uuid="<% out.print(uuid); %>" >Search Product</a>
    <a href=logout.jsp?uuid="<% out.print(uuid); %>" >Logout</a>
</div>