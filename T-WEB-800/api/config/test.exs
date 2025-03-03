import Config

# Configure your database
#
# The MIX_TEST_PARTITION environment variable can be used
# to provide built-in test partitioning in CI environment.
# Run `mix help test` for more information.
config :api, Api.Repo,
  username: "#{System.get_env("POSTGRES_USER")}",
  password: "#{System.get_env("POSTGRES_PASSWORD")}",
  hostname: "#{System.get_env("POSTGRES_HOST")}",
  database: "api_test#{System.get_env("MIX_TEST_PARTITION")}",
  pool: Ecto.Adapters.SQL.Sandbox,
  pool_size: System.schedulers_online() * 2

# We don't run a server during test. If one is required,
# you can enable the server option below.
config :api, ApiWeb.Endpoint,
  http: [ip: {127, 0, 0, 1}, port: 4002],
  secret_key_base: "ItefzgHDrXpnxjqPut5cxZ2HHp8e0+cBUhz4fsovJ6m4iK21MblBMx2D8s0HRft6",
  server: false

# Print only warnings and errors during test
config :logger, level: :warning

# Initialize plugs at runtime for faster test compilation
config :phoenix, :plug_init_mode, :runtime
