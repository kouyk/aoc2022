{
  description = "Flake for AoC 2022 in C++";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system: let
      pkgs = nixpkgs.legacyPackages.${system};
    in {
      devShell = pkgs.mkShell.override { stdenv = pkgs.gcc12Stdenv; } {
        nativeBuildInputs = with pkgs; [ cmake valgrind ];
        buildInputs = with pkgs; [ python3Minimal ];
      };
    });
}
