with Ada.Containers.Vectors;
with Ada.Numerics.Discrete_Random;
with Ada.Text_IO;
with Ada.Integer_Text_IO;

use Ada.Text_IO;
use Ada.Integer_Text_IO;

procedure Insertion_Sort is

   ------------------------------
   -- Constant, types, package --
   ------------------------------

   ARRAY_SIZE : constant Natural := 10;
   RANGE_MIN  : constant Integer := 1;
   RANGE_MAX  : constant Integer := 100;

   package P_Vectors is new Ada.Containers.Vectors (Positive, Integer);
   use P_Vectors;

   -----------------------
   --  Method prototype --
   -----------------------

   --  Initializing an array with default values
   function Init_Vector return Vector;

   procedure Put (Tab : Vector);

   procedure Swap (a : in out Integer; b : in out Integer);

   function Sort (T : Vector) return Vector;

   -----------------------------
   --  Declaration of methods --
   -----------------------------

   function Init_Vector return Vector
   is
      subtype T_Interval is Integer range RANGE_MIN .. RANGE_MAX;
      package P_Random is new Ada.numerics.discrete_random (T_Interval);
      use P_Random;

      seed : Generator;
      T    : Vector;
   begin
      Reset (seed);

      for i in 1 .. ARRAY_SIZE loop
         Append (T, Random (seed));
      end loop;

      return T;
   end Init_Vector;

   procedure Put (Tab : Vector)
   is
   begin
      for e of Tab loop
         Put (e, Width => 0);
         Put (";");
      end loop;
   end Put;

   procedure Swap (a : in out Integer; b : in out Integer)
   is
      c : constant Integer := a;
   begin
      a := b;
      b := c;
   end Swap;

   function Sort (T : Vector) return Vector is
      Tab : Vector := T;
   begin
      for i in First_Index (T) + 1 .. Last_Index (T) loop
         for j in reverse First_Index (T) + 1 .. i loop
            exit when Tab (j - 1) <= Tab (j);
            Swap (Tab (j - 1), Tab (j));
         end loop;
      end loop;
      return Tab;
   end Sort;

   ---------------
   -- Variables --
   ---------------

   T : Vector := Init_Vector;
begin
   Put ("Array        : ");
   Put (T);
   New_Line;

   T := Sort (T);

   Put ("Sorted array : ");
   Put (T);
end Insertion_Sort;
