program KotesPascalProj;

{$L 'kotes.o'}

type
    int_fun = function(x: double): double; cdecl;

function Kotes(f: int_fun; a: double; b: double; n: integer): double; cdecl; external;

function f(x: double): double; cdecl;
begin
  Result:= x*x;
end;

begin
  WriteLn(Kotes(@f, 0, 3, 30);
  readln;
end.

